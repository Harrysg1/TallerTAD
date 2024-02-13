/*
Taller Tad
Profeosor: Jhon corredor 
Materia: Estrucutras de datos 
Estudiantes: Harry Sanchez , Andres Galan, Santiago Barrero
  */

#include <iostream>
using namespace std;

//PUNTO 1

bool Escena:: ActualizarVisual (string nom0bj) {
  // almacenar temporalemtne los objetos extraidos de la escena 
  std::stack<Objeto> aux;
  // para almacenar el objeto actual 
  Objeto miobj;
  // la nube de puntos del objeto
  std::list<Punto> miNube;
  //Un iterador para recorrer la nube de puntos
  std::list<Punto>::iterator punit;
  //Contar puntos dentro y fuera de los limites de la escena 
  int visualTr, visualFl;
  //Arreglo para almacenar las coordenada del punto actual
  float miCoor [3];
  //indicar si se ha encontrado el objeto 
  bool encontrado = false;
  // si se ha actualizado el indicador de visualizacoin 
  bool actualizado = false;
  //Se inicia un bucle para buscar el objeto con el nombre dado en la escena.
  while (!objetos.empty() && ! encontrado) {
    // Se extrae un objeto de la pila "objetos"
    miObj = objetos.top(); 
    objetos.pop();

    // Se compara el nombre del objeto extradio con el nombre dado como parametro 
    if (miObj. Obtener Nombre() == nomObj){
      //Si se encuentra el objeto, se inicializan las variables visualTr y visualFl para contar los puntos dentro y fuera de los límites de la escena.

      encontrado = true;
      miNube = miObj. Obtener Nube();
      visualTr = 0;
      visualF1 = 0;

      //Se recorre la nube de puntos del objeto.
      for (punIt = miNube.begin(); punIt != miNube.end(); punIt++) {
        //Se obtinene las coordenadas del punto actual 
        miCoor = punIt->ObtenerCoord();
        //Se verifica si el punto está dentro de los límites de la escena y se actualizan los contadores visualTr y visualFl en consecuenc
        if (miCoor [0] >= limX [0] && miCoor [0]<= limX [1] &&
            miCoor [1] >= limY [0] && miCoor [1]<= limY [1] &&
            miCoor [2] >= limZ [0] && miCoor [2] <= limZ [1]) {
          visualTr++;
        } else {
          visualFl++;
        }
     }

      
    //Se actualiza el indicador de visualización del objeto en función de la cantidad de puntos dentro y fuera de los límites de la escena.
    if (visualTr == miNube.size() && visualFl miObj.FijarIndVisual ==0) {
      miObj.FijarIndVisual("completa");
      } else if (visualTr == 0 && visualF1 == miNube.size()) {
      miObj.Fijar IndVisual ("nula");
      } else {
      miObj.FijarIndVisual("parcial");
    }
    //Se marca que el objeto ha sido encontrado y actualizado.
    actualizado = true;
    }
    //Se agrega el objeto actual a la pila aux
    aux.push(miObj);
   }
  while (!aux.empty()){
    miObj = aux.top();
    aux.pop()
    objetos.push(miObj);
  }
 //Se vacía la pila aux y se devuelve el valor de actualizado.
  return atualizado;

}
                                                                              
//PUNTO 2: 


bool Escena:: NuevoObjPorUnion (string nom0bj1, string nomObj2) {  
  //Se declara una pila aux para almacenar temporalmente los objetos extraídos de la escena y otra pila objs para almacenar los objetos específicos que coinciden con los nombres dados.

  std::stack<Objeto> aux, objs;
  
  Objeto miobj, miobjU;

  //Se inicia un bucle para extraer objetos de la escena
  while (!objetos.empty()) 
  { 
    miObj = objetos.top(); 
    objetos.pop();
    //Se comprueba si el nombre del objeto actual coincide con alguno de los nombres dados. Si es así, se agrega a la pila objs
    if (miObj.ObtenerNombre() ==nomObj1 || miObj.ObtenerNombre() == nomObj2) {
      objs.push(mi0bj);
    }
  aux.push(miobj);
  }

  //Se declara una lista miNube para almacenar la nube de puntos del objeto actual y otra lista nubeUn para la nube de puntos de la unión de los objetos
  std::list<Punto> miNube, nubeUn; 
  std::list<Punto>::iterator punIt;

  //Se extrae el primer objeto de la pila objs y se obtiene su nube de puntos.
  miObj objs.top(); 
  objs.pop();
  miNube = miObj. ObtenerNube();

  //Se copian todos los puntos de la nube del primer objeto a la lista nubeUn
  for (punit = miNube.begin(); punIt != miNube.end(); punIt++) {     
   nubeun.push_back(*punIt);
  }

  //Se extrae el segundo objeto de la pila objs y se obtiene su nube de puntos.
  miObj = objs.top();
  objs.pop();
  miNube =miobj. ObtenerNube();
//Se copian los puntos de la nube del segundo objeto a la lista nubeUn, omitiendo los puntos que ya existen en la nube del primer objeto.
  for (punIt = miNube.begin(); punIt != miNube.end(); punIt++) {
    if (!miObj.Buscar Punto (*pun It)) nubeUn.push_back(*pun It);

  }

  //Se crea un nuevo objeto (miObjU) que representa la unión de los dos objetos originales y se actualiza su nombre, nube de puntos y centroide.
  miObjU.FijarNombre ("Union " + obj2.Obtener Nombre() + " " +     
  obj1.ObtenerNombre()); 
  miObjU.FijarNube (nubeUn);
  miObjU.ActualizarCentroide();
//Se agrega el nuevo objeto a la pila aux. 
  aux.push(miObjU);
//Se vacía la pila aux y se actualiza la escena con el nuevo objeto.
  while (!aux.empty()) {
    miObj = aux.top();
    aux.pop();
    objetos.push(miobj);
  }

  ActualizarVisual (miObjU);
}
                                                
//Se define una función miembro de la clase Objeto llamada BuscarPunto que busca un punto en la nube de puntos del objeto.
bool Objeto::BuscarPunto (Point p) {
  bool enc = false;
  std::list<Punto>::iterator punit;
  for (punit nube.begin(); punIt != nube.end() && !enc; punIt++) { 
    if (*punit == p) enc = true;
  }
  return enc;
}

//Se define una función miembro de la clase Objeto llamada ActualizarCentroide que calcula el centroide de la nube de puntos del objeto.
void Objeto:: ActualizarCentroide () { 
  float miCoor [3], cent [3]; 
  std::list<Punto>::iterator punit;
  cent [0]= 0.0;
  cent [1]=0.0;
  cent [2]= 0.0;
  for (punIt = nube.begin(); punIt != nube.end(); punIt++) {
    miCoor = punIt->ObtenerCoord();
    cent [0] += miCoor [0];
    cent [1] += miCoor [1];
    cent [2] += miCoor [2];
  }
  cent [0] /= nube.size(); 
  cent [1] /= nube.size();
  cent [2] /= nube.size();
  centroide cent;
}
  





