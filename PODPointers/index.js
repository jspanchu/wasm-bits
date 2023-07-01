import loadPODPointersWasmModule from './fooWeb.js'

var options = {
    print: (function () {
        return function (text) {
            text = Array.prototype.slice.call(arguments).join(' ');
            console.info(text);
        };
    })(),
    printErr: function (text) {
        text = Array.prototype.slice.call(arguments).join(' ');
        console.error(text);
    }
};

let wasmModule = await loadPODPointersWasmModule(options);
console.log("Loaded PODPointers wasm");
var instance = new wasmModule.Foo();

// allocate 100 bytes on the wasm heap.
var buf = wasmModule._malloc(100);
// write 6 32-bit signed integers into that allocation.
var num = 6;
for (var i = 0; i < num; i++) {
    wasmModule.HEAP32[buf + i] = i + 2;
}
instance.setArray(buf, num);
// free allocation
wasmModule._free(buf);
// show the array.
console.log(instance.getArray());
// modify 3rd element.
instance.getArray()[2] = 1;
console.log(instance.getArray());
// allocate 100 bytes on the wasm heap.
var buf = wasmModule._malloc(100);
// write 96 integers to the wasm heap.
var num = 2 * 3 * 4;
for (var i = 0; i < num; i++) {
    wasmModule.HEAP32[buf + i] = i + 2;
}
// pass pointer to shaped array.
instance.setArray3D(buf);
// show contents
console.log(instance.getArray3D());
