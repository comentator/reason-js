open VertexElement;
open VertexData;

module VertexStructure = {

  type vertexStructure = array VertexElement.vertexElement;

  let makeOne = fun (name, vertexData) : vertexStructure => {
      let element : VertexElement.vertexElement = {
          name,
          vertexData
      };

      Array.make 1 element;
  };

}
