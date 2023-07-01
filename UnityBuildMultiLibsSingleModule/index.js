import loadSingleWasmModule from './modJavaScript.js'

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

let wasmModule = await loadSingleWasmModule(options);
console.log("Loaded single wasm module");
let foo = new wasmModule.Foo();
let bar = new wasmModule.Bar();
bar.sayHello("Jaswant");
foo.SetBar(bar);

