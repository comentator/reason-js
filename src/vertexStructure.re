open VertexElement;
open VertexData;

module VertexStructure = {

  type vertexStructure = list VertexElement.vertexElement;

  let makeOne = fun (name, vertexData) => {
      let x : VertexElement.vertexElement = {
          name,
          vertexData
      };

      [x]
  };

}
