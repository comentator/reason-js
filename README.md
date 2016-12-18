# [Reason](http://facebook.github.io/reason/) bindings to JavaScript, through [BuckleScript](http://bloomberg.github.io/bucklescript/Manual.html)

## What Does This Even Mean?

Reason is a syntax on top of OCaml, a great language. BuckleScript compiles OCaml to clean JavaScript. This library provides common JavaScript functions, e.g. `console` and `setInterval`, through Reason (all type checked!); See the usage below!

## Installation

```
npm install reason-js
```

## Usage

```re
/* Looks almost identical to JavaScript, but fully typed! */
let myInterval = ReasonJs.setInterval (fun () => Js.log "hello!") 1000;
```


## XXXX How to build this for our project

```
git clone this-repo
cd this-repo
npm install
npm start
CTRL + C
browserify lib/js/src/example.js > test.js
open test.html
```