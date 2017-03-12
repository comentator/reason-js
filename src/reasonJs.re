type intervalId = Js.Global.intervalId
[@@ocaml.deprecated "Please use `Js.Global.intervalId` instead"];
let setInterval = Js.Global.setInterval
[@@ocaml.deprecated "Please use `Js.Global.setInterval` instead"];
let clearInterval = Js.Global.clearInterval
[@@ocaml.deprecated "Please use `Js.Global.clearInterval` instead"];

type timeoutId = Js.Global.timeoutId
[@@ocaml.deprecated "Please use `Js.Global.timeoutId` instead"];
let setTimeout = Js.Global.setTimeout
[@@ocaml.deprecated "Please use `Js.Global.setTimeout` instead"];
let clearTimeout = Js.Global.clearTimeout
[@@ocaml.deprecated "Please use `Js.Global.clearTimeout` instead"];

external requestAnimationFrame : (unit => unit) => unit = "requestAnimationFrame" [@@bs.val];

external window : DomRe.window = "window" [@@bs.val]
[@@ocaml.deprecated "Please use Dom.window instead"];
external document : DomRe.document = "document" [@@bs.val]
[@@ocaml.deprecated "Please use Dom.document instead"];
external history : DomRe.history = "document.history" [@@bs.val]
[@@ocaml.deprecated "Please use Dom.history instead"];
external location : DomRe.location = "document.location" [@@bs.val]
[@@ocaml.deprecated "Please use Dom.location instead"];

module Base64 = Base64Re;
module Date = Js.Date;
module Json = JsonRe;
module Math = MathRe;
module Object = ObjectRe;
module Promise = Bs_promise
[@@ocaml.deprecated "Please use 'Bs_promise' from the 'bs-promise' package directly instead"];
module RegExp = RegExpRe;

module Dom = DomRe;

/* TODO: Should be moved into Dom */
module CssStyleDeclaration = CssStyleDeclarationRe
[@@ocaml.deprecated "Please use Dom.CssStyleDeclaration instead"];
module Document = DocumentRe
[@@ocaml.deprecated "Please use Dom.Document instead"];
module DomTokenList = DomTokenListRe
[@@ocaml.deprecated "Please use Dom.DomTokenList instead"];
module Element = ElementRe
[@@ocaml.deprecated "Please use Dom.Element instead"];
module Event = EventRe
[@@ocaml.deprecated "Please use Dom.Event instead"];
module EventTarget = EventTargetRe
[@@ocaml.deprecated "Please use Dom.EventTarget instead"];
module History = HistoryRe
[@@ocaml.deprecated "Please use Dom.History instead"];
module HtmlCollection = HtmlCollectionRe
[@@ocaml.deprecated "Please use Dom.HtmlCollection instead"];
module HtmlDocument = HtmlDocumentRe
[@@ocaml.deprecated "Please use Dom.HtmlDocument instead"];
module HtmlElement = HtmlElementRe
[@@ocaml.deprecated "Please use Dom.HtmlElement instead"];
module Location = LocationRe
[@@ocaml.deprecated "Please use Dom.Location instead"];
module Node = NodeRe
[@@ocaml.deprecated "Please use Dom.Node instead"];
module NodeFilter = NodeFilterRe
[@@ocaml.deprecated "Please use Dom.NodeFilter instead"];
module NodeList = NodeListRe
[@@ocaml.deprecated "Please use Dom.NodeList instead"];
module Range = RangeRe
[@@ocaml.deprecated "Please use Dom.Range instead"];
module Selection = SelectionRe
[@@ocaml.deprecated "Please use Dom.Selection instead"];
module Window = WindowRe
[@@ocaml.deprecated "Please use Dom.Window instead"];

module Fetch = FetchRe;

module Float32Array = Float32ArrayRe;
module Gl = GlRe;
module Uint16Array = Uint16ArrayRe;

module Storage = StorageRe;

module CanvasElement = {
  external getContext : DomRe.element => string => Gl.glT = "getContext" [@@bs.send];
};
