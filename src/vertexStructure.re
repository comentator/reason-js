open VertexElement;
open VertexData;

module VertexStructure = {

  type vertexStructure = array VertexElement.vertexElement;

  let makeOne = fun (name, vertexData) => {
      let x : VertexElement.vertexElement = {
          name,
          vertexData
      };

      Array.make 1 x;
  };

}
