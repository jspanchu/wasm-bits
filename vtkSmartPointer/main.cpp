#include "vtkLogger.h"
#include "vtkNew.h"
#include "vtkObject.h"
#include "vtkObjectFactory.h"
#include "vtkSmartPointer.h"

#include "emscripten/bind.h"

namespace emscripten {
// Teaches emscripten to work with vtkSmartPointer. All vtkObjects will
// be constructed through vtkSmartPointer<T>::New
template <typename T> struct smart_ptr_trait<vtkSmartPointer<T>> {
  using pointer_type = vtkSmartPointer<T>;
  using element_type = T;

  static sharing_policy get_sharing_policy() {
    // Intrusive because element_type is a vtkObject derived instance which
    // keeps reference count.
    return sharing_policy::INTRUSIVE;
  }

  static element_type *get(const pointer_type &p) { return p.Get(); }

  static pointer_type share(const pointer_type &r, T *ptr) {
    return pointer_type(ptr);
  }

  static pointer_type *construct_null() { return new pointer_type; }
};
} // namespace emscripten

// Example custom object derived vtkObject
class vtkCustomObject : public vtkObject {
public:
  vtkTypeMacro(vtkCustomObject, vtkObject);
  void PrintSelf(ostream &os, vtkIndent indent) override {}
  static vtkCustomObject *New();

protected:
  vtkCustomObject(){vtkLog(INFO, << "Constructed " << vtkLogIdentifier(this))};
  ~vtkCustomObject() {
    vtkLog(INFO, << "Destroyed " << vtkLogIdentifier(this));
  }

private:
  vtkCustomObject(const vtkCustomObject &) = delete;
  void operator=(const vtkCustomObject &) = delete;
};

vtkStandardNewMacro(vtkCustomObject);

// Teaches emscripten how to delete vtkObject derived instances.
#define vtkAddDestructor(cname)                                                \
  template <> void emscripten::internal::raw_destructor<cname>(cname * ptr) {  \
    ptr->Delete();                                                             \
  }

vtkAddDestructor(vtkObjectBase);
vtkAddDestructor(vtkObject);
vtkAddDestructor(vtkCustomObject);

// Similar to std::make_shared<T>
template <typename T> vtkSmartPointer<T> MakeVTKSmartPtr() {
  return vtkSmartPointer<T>::New();
}

// Binding code
EMSCRIPTEN_BINDINGS(vtksmartptr_prototype) {
  emscripten::class_<vtkObjectBase>("vtkObjectBase");
  emscripten::class_<vtkObject, emscripten::base<vtkObjectBase>>("vtkObject")
      .smart_ptr<vtkSmartPointer<vtkObject>>("vtkSmartPointer<vtkObject>")
      .constructor(&MakeVTKSmartPtr<vtkObject>)
      .function("GetReferenceCount", &vtkObject::GetReferenceCount);
  emscripten::class_<vtkCustomObject, emscripten::base<vtkObject>>(
      "vtkCustomObject")
      .smart_ptr<vtkSmartPointer<vtkCustomObject>>("vtkSmartPointer<vtkCustomObject>")
      .constructor(&MakeVTKSmartPtr<vtkCustomObject>);
}
