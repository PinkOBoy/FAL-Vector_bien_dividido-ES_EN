/*
* @author PinkOBoy
*/
/* - RESUMEN DEL ENUNCIADO // SUMING UP THE INSTRUCTIONS ---------
* - SPANISH ------------------------------------------------------
* Dado un vector de enteros y una posicion, decimos que un vector
* esta "bien dividido" cuando el maximo valor entre el inicio y la
* esa posicion es menor estricto que el minimo valor entre la 
* posicion y el final del vector.
* 
* - ENGLISH ------------------------------------------------------
* Given a integer vector and a position, we say a vector is "well
* divided" when the maximum value between the beginning of the 
* vector and the position is strictly lesser than the minimum value
* between the position and the end of the vector.
*/
#include <iostream>
#include <vector>
using namespace std;

// - PROTOTIPOS ---------------------------------------------------
// - PROTOTYPES

/* PRECONDITION:
*	1 <= v.size() <= 10^4
* ^
*	0 <= p < v.size()
*/

bool resolver(
	const vector<int>& v,// vector de enteros // integer vector
	int position		 // posicion del vector // position from the vector
); // return bienDividido

/* POSTCONDITION:
* bienDividido =
*	MAX i : 0 <= i <= position : v[i] < MIN j : position < j < v.size() : v[j]
*/

// - MAIN ---------------------------------------------------------

void solve() {
	int n, p;
	cin >> n >> p;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	if (p == n - 1 || resolver(v, p))
		cout << "SI" << endl;
	else cout << "NO" << endl;
}

int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; ++i)
		solve();

	return 0;
}

// - IMPLEMENTACIONES ---------------------------------------------
// - IMPLEMENTATIONS

// - SPANISH ------------------------------------------------------
/* COMPLEJIDAD DEl ALGORITMO
* Todas las instrucciones ejecutadas tienen un coste de eficiencia constante.
* 
* Defiendo:
* 
*	n::= numero de elementos del vector = v.size()
* 
* Afirmamos que existen dos bucles en el algoritmo. El primer bucle analiza
* siempre los position + 1 primeros elementos del vector. El segundo,
* en el peor de los casos, recorre los n - (position + 1), es decir,
* en total:
* 
*	position + 1 + n - (position + 1) = n = v.size()
* 
* Por ello, podemos afirmar que la complejidad del algoritmo es:
* 
*	O(n)
*/

// - ENGLISH ------------------------------------------------------
/* COMPLEXITY OF THE ALGORITHM
* All executed instructions has a constant efficient cost.
* 
* Defining:
* 
*	n::= amount of elements of the vector = v.size()
* 
* We affirm the existence of two loops in the algorithm. The first loop
* always analyzes the position + 1 first elements of the vector. The second
* one, in the worst case scenario, ranges between the n - (position + 1),
* that is, in total the algorithm ranges:
* 
*	position + 1 + n - (position + 1) = n = v.size()
* 
* Thus, we can affirm that the complexity of the algorithm is:
* 
*	O(n)
*/

bool resolver(
	const vector<int>& v,
	int position
) {
	bool bienDivido = true;
	int mayorIzq = v[0], i;

	/* - FUNCION DE COTA --------
	* fc(x) = p + 1 - i
	*/
	for (i = 1; i <= position; ++i)
		if (mayorIzq < v[i])
			mayorIzq = v[i];
	/* - INVARIANTE -------------
	*	0 <= i <= position + 1
	* ^
	*	mayorIzq = MAX e : 0 <= e < i : v[e]
	*/

	/* - FUNCION DE COTA --------
	* fc(x) = v.size() - i
	*/
	while (bienDivido && i < v.size()) {
		bienDivido = v[i] > mayorIzq;
		++i;
	}
	/* - INVARIANTE -------------
	*	position < i <= v.size()
	* ^
	*	bienDivido =
	*		mayorIzq < MIN r : position + 1 <= r < i : v[r]
	*/

	return bienDivido;
}