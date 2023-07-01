import loadWasmModuleA from './modAJavaScript.js'
import loadWasmModuleB from './modBJavaScript.js'

var optionsA = {
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

var optionsB = Object.assign({}, optionsA);

let wasmModuleA = await loadWasmModuleA(optionsA);
console.log("Loaded ModuleA Wasm");
let foo = new wasmModuleA.Foo();

let wasmModuleB = await loadWasmModuleB(optionsB);
console.log("Loaded ModuleB Wasm");
let bar = new wasmModuleB.Bar();
bar.sayHello("Jaswant");
foo.SetBar(bar);

