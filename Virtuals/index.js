import loadVirtualsWasmModule from './fooWeb.js'

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

let wasmModule = await loadVirtualsWasmModule(options);
console.log("Loaded Virtuals wasm");
var FooDerived = {
    GetClassNameImplementation: function() {
        return 'FooDerived'
    }
};
var instance = wasmModule.Foo.implement(FooDerived);
console.log(instance.GetClassName());
