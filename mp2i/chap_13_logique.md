# Chapitre 13 : Logique

objectif : formaliser le discours, le raisonnement, la démonstration.

$\leadsto$ __Syntaxe__: règles, outils permettant d'écrire des formules.

$\leadsto$ __Sémantique__: sens, interprétation des formules.

## I. Syntace des formules

### 1. Formules propositionnelles

__Def__: Une *variable propositionnelle* est une proposition élémentaire pouvant être vraie ou fausse.

__Def__: Les *constantes logiques* sont $\begin{cases} \top \space \text{désignant une proposition toujours vraie} \\ \bot \space \text{----- fausse.}  \end{cases}$

__Def__: Soit $\mathcal{V}$ l'ensemble des variables propositionnnelles on définit uninductivemment l'ensemble $\mathcal{P}_\mathcal{V}$ des formules propositionnnelles.

__Assetions__ :

- une vatiable est une formule: $\mathcal{V} \subset \mathcal{P}_\mathcal{V}$.
- les consantes logiques sont des formules i.e. $\top \in \mathcal{P}_\mathcal{V}$ et $\bot \in \mathcal{P}_\mathcal{V}$

__Règles d'inférences__ :

- Soit $\neg$ le connecteur de négation et $\varphi \in \mathcal{P}_\mathcal{V}$. Alors $\neg \varphi \in \mathcal{P}_\mathcal{V}$
- Soit $\land$ le connecteur de conjonction et $\psi$ et $\varphi \in \mathcal{P}_\mathcal{V}$. Alors $(\psi \land \varphi) \in \mathcal{P}_\mathcal{V}$.
- Soient $\lor$ le connecteur de disjonction, $\rightarrow$ le connecteur d'implication et $\leftrightarrow$ le connnecteur d'équivalence. Soient $\psi$ et $\varphi \in \mathcal{P}_\mathcal{V}$. Alors $(\psi \lor \varphi) \in \mathcal{P}_\mathcal{V}, (\psi \rightarrow \varphi) \in \mathcal{P}_\mathcal{V}$ et $(\psi \leftrightarrow \varphi) \in \mathcal{P}_\mathcal{V}$

Ex:

- "Il pleut et je prends mon parapluie." Soit $x$ la variable signifiant "Il pleut", et $y$ la variable "Je prends mon parapluie". Alors la phrase devient $(x \land y)$.

- "Si j'ai cours de math ou si j'ai cours d'info alors je prends mon cahier." On pose $x$ la variable propositionnelle signifiant "j'ai cours de math", $y$ signifiant "j'ai cours d'info" et $z$ signifiant "je prends mon cahier". On a alors $((x \lor y) \rightarrow z)$

__Représentation arborescente__ : Toute formule propositionnelle peut être représentée par un arbre. Dans un arbre $\top$ et $\bot$ sont des feuilles et
$\diamonds \in \{\land, \lor, \rightarrow, \leftrightarrow\}$ en noeud interne.

Propsitions:

- Les représentations arborescentes des formules prop. sont des arbres binaires non stricts. Rmp: connecteurs $\neg$ est d'arité 1 et connnecters $\land, \lor, \rightarrow, \leftrightarrow$ sont d'arrité 2.
- La syntaxe de la fomule se retrouve avec un parcours *infixe* de la repr arboresente.

$\leadsto$ Repr d'une formule en C / OCaml.

```OCaml
type 'a fp = 
    | Var of 'a
    | Top
    | Bottom
    | Not of 'a fp
    | Or of ('a fp * 'a fp)
    | And of ('a fp * 'a fp)
    | Impl of ('a fp * 'a fp)
    | Iff of ('a fp * 'a fp)
```

```C
struct fp_s {
    char* etiquette; // un type énuméré ne fonctionne pas 
    // pour les variables prop.
    // Il faut vérifier que les règles syntaxiques sont respectés.
    struct fp_s* gauche;
    struct fp_s* droite;
};
```
