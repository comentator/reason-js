open Array;
open VertexElement;
open VertexData;

module VertexStructure = {

  type vertexStructure = {
    elements: array VertexElement.vertexElement
  };

  type element = {
      name: string,
      vertexData: VertexData.vertexdata
  };

  let makeOne = fun (name, vertexData) => {
      let x : element = {
          name,
          vertexData
      };

      [x]
  };

}
