# Langage C++

Ce dépôt contient les travaux pratiques réalisés en langage C++.

## TD1

Le TD1 est divisé en deux parties :

- `Exercice1` : affichage de texte, fonctions et classe `My_class`.
- `Exercice2` : classe `Complex2D`, constructeurs, getters, setters et opérateurs.

### Compiler l'exercice 1

```bash
cd TD1/Exercice1
g++ main.cpp function.cpp My_class.cpp -o exercice1
./exercice1
```

### Compiler l'exercice 2

```bash
cd TD1/Exercice2
g++ main.cpp Complex2D.cpp -o exercice2
./exercice2
```

## TD2

Le TD2 est divisé en deux parties :

- `Exercice1` : recherche linéaire, recherche par saut et recherche binaire.
- `Exercice2` : matrices génériques et numériques, déterminant, opérateurs, inverse et matrice identité.

### Compiler l'exercice 1

```bash
cd TD2/Exercice1
g++ main.cpp SearchingAlgorithm.cpp LinearSearch.cpp JumpSearch.cpp BinarySearch.cpp -o exercice1
./exercice1
```

### Compiler l'exercice 2

```bash
cd TD2/Exercice2
g++ main.cpp -o exercice2
./exercice2
```

## TD3

Le TD3 contient trois exercices :

- `Exercice1.cpp` : comptage des fréquences avec une méthode brute-force et une `map`.
- `Exercice2.cpp` : problème Two Sum avec une méthode brute-force et une `unordered_map`.
- `Exercice3.cpp` : vérification d'un palindrome avec une `queue` et une `stack`.

### Compiler et exécuter les exercices

```bash
cd TD3

g++ Exercice1.cpp -o Exercice1
./Exercice1

g++ Exercice2.cpp -o Exercice2
./Exercice2

g++ Exercice3.cpp -o Exercice3
./Exercice3
```
