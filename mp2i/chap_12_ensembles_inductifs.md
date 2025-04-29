# Chapitre 12 : Ensemble Ordonnées et inductifs

## Partie 0: À savoir

### Vocabulaire à connître

- __Ensembles ordonnés:__
  - reflecive, transitive, symétrie, anti-symétrie
  - relation d'équivalence
  - relation d'ordre
  - prédécesseur.successeur $\pm$ immédiat
  - ordre __total__
  - elt minimal / maximal
  - minimum / maxium
  - ensemble __bien fondé__
- __Esembles inductifs:__
  - assertion, règle d'inférence
  - __dérivation__
  - __ambiguté__

### Savoir faire

- __Esembles ordonnés:__
  - Dessiner le graphe associé à un ensemble ordonné (p.4 du poly)
- __Esembles inductifs:__
  - définir un ensemble inductivement

### À savoir par coeur

- ⚠️ Théorème page 6. "Enseble bien fondé $\iff$ il n'existe pas de suite strictement décroissante."
- Métode pour la terminaison.
  1. Munir chaque $\begin{cases} \text{variable de boucle} \\ \text{paramètre de la fonction récursive} \end{cases}$ d'un ordre bien fondé. Munir l'ensemble d'un ordre produit / lexicographique qui est par définition bien fondé.
  2. Montrer sa stricte décroissance $\begin{cases} \text{d'un appel rec au suivant} \\ \text{d'une itération à la suivante} \end{cases}$.
  3. citer le théorème ci dessus pour justifier que le nombre $\begin{cases} \text{d'appels réc} \\ \text{d'itérations} \end{cases}$ est bien fini puis vérifier la terminaison du reste des instruction.

__La suite du fichier donne la corréction de la plupart des exos du poly.__

## Partie I

### Partie 2

- Tout sommet est accessible de lui même par un chemin de longueur 0. $\to R$ est reflexive.
- En mettant bout à bout les chemin on a la transitivité de $R$
- La symétrie est triviale.

### Partie 3

#### Exo 1

- Même argument pour la réflexibilité.
- IDEM pour la transitivité.
- Comme le graphe est acyclique si 2 sommets $\neq$ alors on a un cycle ce qui n'est pas possible. D'où l'anti-symétrie.

#### Exo 2

![image](ressources/chap_12/graphe_ensemble_ordonnée.png)

#### Exo 4

Par l'absurde: Si le graphe est cyclique.
Alors il existe un chemin de taille $n$ (non nul) tel que $s_1 s_2\dots s_n s_1$ soit un cycle.
Donc $s_2 \prec s_n$ et $s_n \prec s_2$, absurde.
Donc le graphe est acyclique.

### Partie 5

#### Exo 1 (partie b)

Q1.

$x \in \N$ et $y \in \N$ et $(\N, \leq)$ est bien fondé donc par définition l'ordre lexicographique sur $(x, y)$ est bien fondé.
Soit $\tilde x, \tilde y$ les valeurs de $x$ et $y$ en fin d'itération. Montrons que $(\tilde x, \tilde y) < (x, y)$ selon l'ordre lexicographique:

- 1er cas `SI` $\tilde x = x$ et $\tilde y = y -1$ or $(x, y-1) < (x, y)$
- 2eme cas `SINON` $\tilde x = x-1$ et $\tilde y = 4x + 7$ or $(x-1, 4x+7) < (x, y)$

Il n'existe pas de suite infinie strictement décroissante à valeurs dans un ensemble bien fondé. Donc le nombre d'itération de la boucle est finie. Le reste des instructions terminent trivialement, donc la boucle termine.

Q2.

$n \in \N$ et $m \in \N$ et $(\N, \leq)$ est bien fondé donc par définition l'ordre lexicographique sur $(n, m)$ est bien fondé.
Soit $\tilde n, \tilde m$ les valeurs de $n$ et $m$ en fin d'itération. Montrons que $(\tilde n, \tilde m) < (n, m)$ selon l'ordre lexicographique:

- 1er cas `SI` $\tilde n = n$ et $\tilde m = m - n$ or $(n, m-n) < (n, m)$
- 2eme cas `SINON` $\tilde n = n-1$ et $\tilde m = 2m$ or $(n-1, 2m) < (n, m)$

Il n'existe pas de suite infinie strictement décroissante à valeurs dans un ensemble bien fondé. Donc le nombre d'itération de la boucle est finie. Le reste des instructions terminent trivialement, donc la boucle termine.

Q3.

Ordre lexicographique avec $(l-i, c-j)$.

#### Exo 2 (partie c)

Q1.

$a \in \N$, $b \in \N$ et $c \in \N$ et $(\N, \leq)$ est bien fondé donc par définition l'ordre lexicographique sur $(a, b, c)$ est bien fondé.
Soit $\tilde a, \tilde b, \tilde c$ les valeurs de $a$, $b$ et $c$ en fin d'itération. Montrons que $(\tilde a, \tilde b, \tilde c) < (a, b, c)$ selon l'ordre lexicographique:

- Les 2 premier cas termine trivialement.
- 3eme cas `a = b + c`
  - 1er appel : $\tilde a = a$, $\tilde b = 0$ et $\tilde c = c-1$ or $(a, 0, c-1) < (a, b, c)$
  - 2eme appel : $\tilde a = a$, $\tilde b = b-1$ et $\tilde c = x \in \N$ or $(a, b-1, x) < (a, b, c)$
- 4eme cas `SINON`
  - 1er appel : $\tilde a = a$, $\tilde b = b-1$ et $\tilde c = c+1$ or $(a, b-1, c+1) < (a, b, c)$
  - 2eme appel : $\tilde a = a$, $\tilde b = b$ et $\tilde c = c-1$ or $(a, b, c-1) < (a, b, c)$
  - 3eme appel : $\tilde a = a-1$, $\tilde b = x \in \N$ et $\tilde c = y \in \N$ or $(a-1, x, y) < (a, b, c)$

Il n'existe pas de suite infinie strictement décroissante à valeurs dans un ensemble bien fondé. Donc le nombre d'itération de la boucle est finie. Le reste des instructions terminent trivialement, donc la boucle termine.

Q2.

Exercice laissé au soin du lecteur.

## Partie II

### Partie 1

#### Exercice 1

Q1.

- Assetion : $n = 0$ pour les entiers pairs $n = 1$ pour les impairs.
- Règle d'inférence : Soit $n$ un entier pair/impair $S = n \pm 2$.

Q2.
$\Z^*$

Q3. Voir chapitre sur les arbres.

#### Exercice 2

On note $S_1 = x \mapsto 2x$, $S_2 = x \mapsto 2x + 1$ et $S_3 = x \mapsto -x$. Alors $-14 = S_3(S_2(S_1(S_1(\mathbb(1)))))$
