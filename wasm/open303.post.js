/* global Module */

"use strict";

console.log(
	"running%c Open303 (Wasm)",
	"font-weight: bold; color: #bada55"
);



//NOTE: This is the main thing that post.js adds to the setup, a Module export definition which is required for the WASM design pattern
export default Module;
