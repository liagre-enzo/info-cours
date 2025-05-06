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

Pour simplifier les écritures on définit pour la suite du cours $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ le connecteur générique.

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

### 2. Fonctions sur les formules propositionnnelles

$\leadsto$ __Taille__ d'une formule prop

Idée $=$ taille de l'arbre.

*Définition inductive* de la taille $\mathcal{T}$:

- Assertions : $\mathcal{T}(\top) = 1$ et $\mathcal{T}(\bot) = 1$. Soit $v \in \mathcal{V}$ alors $\mathcal{T}(v) = 1$
- Règles d'inférence :
  - Soit $\varphi \in \mathcal{P}_\mathcal{V}$ alors $\mathcal{T}(\neg \varphi) = 1 + \mathcal{T}(\varphi)$.
  - Soient $\varphi, \psi \in \mathcal{P}_\mathcal{V}$ et connecteur $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ alors $\mathcal{T}(\varphi \diamonds \psi) = 1 + \mathcal{T}(\varphi) + \mathcal{T}(\psi)$

$\leadsto$ __Hauteur__ d'une formule prop

Idée $=$ hauteur de l'arbre.

*Définition inductive* de la hauteur $\mathcal{H}$:

- Assertions : $\mathcal{H}(\top) = 0$ et $\mathcal{H}(\bot) = 0$. Soit $v \in \mathcal{V}$ alors $\mathcal{H}(v) = 0$
- Règles d'inférence :
  - Soit $\varphi \in \mathcal{P}_\mathcal{V}$ alors $\mathcal{H}(\neg \varphi) = 1 + \mathcal{H}(\varphi)$.
  - Soient $\varphi, \psi \in \mathcal{P}_\mathcal{V}$ et connecteur $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ alors $\mathcal{H}(\varphi \diamonds \psi) = 1 + max(\mathcal{H}(\varphi), \mathcal{H}(\psi))$

$\leadsto$ __Sous-formule__ d'une formule prop

Idée $=$ une sous-formule est une partie de la formule qui est syntaciquement une formule prop.

*Définition inductive* de $\mathcal{S_F}$ l'ensemble des sous formules.:

- Assertions : $\mathcal{S_F}(\top) = \top$ et $\mathcal{S_F}(\bot) = \bot$. Soit $v \in \mathcal{V}$ alors $\mathcal{S_F}(v) = \{v\}$
- Règles d'inférence :
  - Soit $\varphi \in \mathcal{P}_\mathcal{V}$ alors $\mathcal{S_F}(\neg \varphi) = \{\neg \varphi\} \cup \mathcal{S_F}(\varphi)$.
  - Soient $\varphi, \psi \in \mathcal{P}_\mathcal{V}$ et connecteur $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ alors $\mathcal{S_F}(\varphi \diamonds \psi) = \{\varphi \diamonds \psi\} \cup \mathcal{S_F}(\varphi) \cup \mathcal{S_F}(\psi)$

$\leadsto$ __Sous-formule__ d'une variable par une formule prop

Idée $=$ remplacer la variable à chaque endroit où la variable est présente dans la formule.

*Définition inductive* de $\varphi[\psi/x]$ substitution de $x$ par $\psi$ dans la formule $\varphi$:

- Assertions : $\top[\psi/x] = \top$ et $\bot[\psi/x] = \bot$. Soit $v \in \mathcal{V}$ alors $\begin{cases} v[\psi/x] = \psi \space \text{si} \space v = x \\ v[\psi/x] = v \space \text{sinon}  \end{cases}$
- Règles d'inférence :
  - Soit $\varphi \in \mathcal{P}_\mathcal{V}$ alors $(\neg \varphi) [\psi/x] = \neg (\varphi[\psi/x])$.
  - Soient $\varphi, \varphi' \in \mathcal{P}_\mathcal{V}$ et connecteur $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ alors $(\varphi \diamonds \varphi') [\psi/x] = (\varphi[\psi/x] \diamonds \varphi'[\psi/x])$

### 3. Logique du $1^{er}$ ordre

Objectif : pouvoir manipuler des objets qui ne sont pas justes "vrai ou faux".

Exemple : $2 \leq x + 1 < 3y$.

- __Def__ (domaine): un domaine est composé
  - d'un ensemble de variables $X$
  - d'un ensemble de fonctions d'arité $a$ définies sur $X^{a}$ noté $S_f^{a}$.
  - d'un ensemble de prédicats d'arrité $a$ noté $S_p^a$.

- __Def__ (terme):
  - Toute variable de $X$ est un terme.
  - Si $f \in S_f^a$ et $t_1, t_2, \dots, t_a$ sont des termes alors $f(t_1, t_2, \dots, t_a)$ est un terme.
  
- __Def__ (atome) : Si $t_1, t_2, \dots, t_a$ sont des termes et $p \in S_p^a$ alors $p(t_1, t_2, \dots, t_a)$ est un atome.

Retour sur l'exemple : $2 \leq x + 1 < 3y$

- Domaine :
  - $X = \{x, y\}$
  - $S_f^2 = \{+, \times\}$
  - $S_f⁰ = \{1, 2, 3\}$
  - $S_p¹ = \{\leq\}$

Exemple 2 : "Tous les hommes sont mortels. Socrate est un homme. Donc Socrate est mortel." Pour transformer cette phrase il nous faut les quantificateur.

- __Def__ (quantificateurs):
  - Le symbole $\forall$ désigne le quantificateur universel.
  - Le symbole $\exists$ désigne le quantificateur existentiel.

- __Def__ de l'ensemble des formules du premier ordre sur un domaine.
  - Assertion: un atome est une formule du premier ordre.
  - Règles d'inférence:
    - Si $\varphi$ est une formle du permier ordre et $\neg$ le connecteur de négation alors $\neg \varphi$ est une formule du permier ordre.
    - Si $\varphi$ et $\psi$ sont des formles du permier ordre alors $(\varphi \diamonds \psi)$ est une formule du premier ordre et $\diamonds \in \{\lor, \land, \rightarrow, \leftrightarrow\}$ connecteur d'arité 2.
    - Si $\varphi$ est une formule du permier ordre et $x$ une variable de $X$ alors $\begin{cases} \forall x \cdot \varphi \\ \exists x \cdot \varphi \end{cases}$ sont des formules du permier ordre.

On peut représenter les formules par un arbre.

Ex : Formule du premier ordre $((\forall A, \space \forall B, \space A \cap B \subseteq A) \land (\emptyset \subseteq A))$.

- Domaine :
  - $X = \{1, B\}$
  - $S_f⁰ = \{\emptyset\}$
  - $S_f² = \{\cap\}$
  - $S_p² = \{\subseteq\}$

- Arbre ![image](ressources/chap_13/exemple_formule_premier_ordre.png)

__Vocabulaire__ :

- *Portée* d'une variable $x$ dans une formule $\begin{cases} \forall x \cdot \varphi \\ \exists x \cdot \varphi \end{cases}$ est la formule $\varphi$.

- Variable *libre/liée* : une occurrence d'une variable $x$ est $\begin{cases} \text{liée} \\ \text{libre} \end{cases}$ si elle $\begin{cases} \text{apparaît} \\ \text{n'apparaît plus} \end{cases}$ à la suite d'un $\begin{cases} \forall x \cdot \\ \exists x \cdot \end{cases}$. Une variable est dite $\begin{cases} \text{liée} \\ \text{libre} \end{cases}$ si elle a au moins une occurrence $\begin{cases} \text{liée} \\ \text{libre} \end{cases}$.
  
Ex: Dans la formule précédente $A$ libre et liée et $B$ liée.

$\mapsto$ Les fonctions inductives sur l'ensemble des formules propositionnnelles pourraient être définies sur les formules du premier ordre.
Attention pour la substitution, on ne peut pas substituer les variables liées.

## II. Sémentique
