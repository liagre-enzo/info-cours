# Chapitre 17 : Algothmique du texte

> __Vocabulaire__
>
> Un __Alphabet__ $\Sigma$ est un ensemble fini non vide de caractères.
>
> Un __mot__ sur un alphabet est une suite de caractères. Le mot vide est noté $\varepsilon$
>
> L'ensemble des mots de longeur $n$ sur l'alphabet $\Sigma$ est noté $\Sigma ^n$ . L'ensemble des mots est noté $\Sigma ^*$ .
>
> La __concaténation__ de deux mots $m$ et $n$ sur le même alphabet $\Sigma$ , noté $m \cdot n$ est la suite composée des caractères de m puis de n.
>
> Un __préfixe__ d'un mot $m \in \Sigma ^*$ est un mot $p$ tel qu'il existe $n \in \Sigma ^*$ tel que $m = p \cdot n$ .
>
> Un __suffixe__ d'un mot $m \in \Sigma ^*$ est un mot $s$ tel qu'il existe $n \in \Sigma ^*$ tel que $m = n \cdot s$ .
>
> Un __facteur__ d'un mot $m \in \Sigma ^*$ est un mot $f$ tel qu'il existe $n \in \Sigma ^*$ et $n' \in \Sigma ^*$ tel que $m = n \cdot f \cdot n'$ .

- Proposition : Un mot de longeur $n$
  - $n+1$ préfixes
  - $n+1$ suffixes
  - au plus $1 + \frac{n(n+1)}{2}$ facteurs

> Algorithmique du texte regroupe tous les algos pour lesquelles la taille de l'alphabet est négligeable devant la taille des mots.

## I. Recherche

- Enoncé du pb :
  - Entrées :
    - deux mots $m$ et $t$ sur un alphabet $\Sigma ^*$ avec la taille de $m$ inférieure (souvent de beaucoup) à la taille de $t$ .
    - Sortie booléen indiquant si $m$ est un facteur de $f$ .

### 1. Rabin-Karp

- Idée à chaque indice de $t$ , on ne fait pas toutes les comparaisons, donc on ne parcourt pas tout $m$ . Pour cela, on utilise une fct de hachage et on compare leurs résultats : $O(1)$ car ce sont des entiers.
