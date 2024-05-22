# system-programming-2-assignment-2
ID - 208768978
GMAIL - michibinyamin@gmail.com
אכתוב באנגלית כדיי לשמור על סדר המילים וכי זה יותר נוח לי

assumptions : 
- The exeptions that i am throwing is only in the case where two squre matricies have diffarent sizes, assuming they are both squre(becuse if they were not squre then they whould not be created in the loading stage, the exeption would be thrown before the comparison)


**Operaters** 

**Arothmatic operators** 

- operator+ : only if matricies size are the same the function adds all the corrusponding values and returns a new matrix

- operator+ unary : the function adds all the values to the new matrix and returns it

- operator- :   only if matricies size are the same the function subtracts all the corrusponding values and returns a new matrix

- operator- unary : the function adds all the values times -1 to the new matrix and returns it

- operator+= :  like operator+ but chenges the current graph

- operator-= :  like operator- but chenges the current graph

- operator++ :  itarates through the edges and adds one to all of them

- operator-- :  itarates through the edges and subtracts one to all of them

- operator* with a skalar : itarates through the edges and times each one with the skalar

- operator*= with a skalar : like operator* but chenges the current graph

- operator/ with a skalar : itarates through the edges and devides each one with the skalar

- operator/= with a skalar : like operator/ but chenges the current graph

- operator* with another matrix : i have done here a algorithem which multiplys two matricies as we know, if sizes are not the same then it throws an exeption. the graphs can only be squre in our project.

- operator*= with another matrix : same as operator* but chenges the current graph

**Comparisson operators** 
- iscontains : a method i made to check if a graph is containd in another

- operator> : checks if one is bigger to the other with contains, number of edges and number of vertecies

- operator>= : checks if !operator<

- operator< : checks if one is smaller then the other with contains, number of edges and number of vertecies

- operator<= : checks if !operator>

- operator== : checks if the graphs are identicle, if not then checks if each one is not bigger then the other

- operator!= : checks if !operator==


**General** 
- operator<< : the << operator overload does not belong to the class

- I have added a method which returns a string of the graph, this way i can test the graphs values with a string representation

- I have added examples in the main.cpp by printing graphs, changing them and comparing.