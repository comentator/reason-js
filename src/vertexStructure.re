open Array;
open VertexElement;
module VertexStructure = {
  type vertexdata =
      | Float1
      | Float2
      | Float3
      | Float4;
      /* ToDo: | Float4x4; */
  type vertexStructure = {
    elements:array VertexElement.vertexElement
  };
  type element = {
      name: string,
      vertexData: vertexdata
  };
  let makeOne = fun (name, vertexData) => {
      let x : element = {
          name,
          vertexData
      };

      [x]
  };
}
