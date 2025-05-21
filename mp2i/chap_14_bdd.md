# Chap 14 : Bases de données

## I. Conception d'une base de données

### 1. Paradiqme logique

> __Définition__
>
> Les programmes respectant le paradigme logique sont des descriptions des proporiétés que le résultat doit respecter sans aucune indication sur la manière de le calculer.

Ce sont les *systèmes de géstion des bases de donnés (SGBD)* qui s'occupent du fonctionnement "interne" de la base.

$\underline{\text{Missions des SGBD :}}$

- Organisation de la mémoire *efficace* $=$ choix des supposrts physiques et des supports physiques et des structures de données.
- Maintenance, gestion des pannes.
- Gérer les accès à la base (quel utilisateur a le droit de faire quoi).
- Garanti d'afficacit" maximale de toutes les opérations.
- Permettre à l'utilisateur de manipuler les données via des *requêtes*. Les requêtes respectent le principe __ACID__.

$$
\begin{align*}
    \text{A} &= \text{atomicité} \\
    \text{C} &= \text{cohérence} \\
    \text{I} &= \text{isolation} \\
    \text{D} &= \text{durabilité}
\end{align*}
$$

### 2. Modéle entité-association

$\underline{\text{Objectif}}$ : visualiser les données à stocker dans la base.

> __Def__
>
> Une __entité__ est un objet (au sens large) qu'on veur stocker. Les entités ont des __propriétés__ (informations la concernant).
>
> Un __type entité__ regroupe des entités ayant le même type de propiétés.

$\underline{\text{Représentation Graphique d'un type entité}}$

![image](ressources/chap_14/type_entite.png)

$\underline{\text{Exemple}}$

![image](ressources/chap_14/exemple_type_entite.png)

Chaque entité doit pouvoir être identifiée de manière __unique__ au sein du type auquel elle appartient.

Si nécessaire on peut ajouter une propriété à cet effet.

> __Def__
>
> - Une __association__ représente un lein entre différentes entités.
> Une association peut aussi avoir des propriétés.
> - Un __type assiciation__ regroupe des associations reliant des entités appartenant au même type-entité et ayant les même propriétés.

$\underline{\text{Représentation Graphique d'un type entité}}$

![image](ressources/chap_14/repr_type_association.png)

$\underline{\text{Exemple}}$

![image](ressources/chap_14/ex_type_association.png)

$\to$ Pour être stocké, tout type-association doit être __binaire__ (relier 2 types-entités).

> __Idée__: transformer le type-association en un type-entité et recréer des types-associations pour tout relier.

![image](ressources/chap_14/type_associat_non_binar.png)

Devient :

![image](ressources/chap_14/type_associat_binar.png)

Tous les types associations sont aussi binaires.

> __Définition__:
>
> Chaque type-entité participant à un type-association a une contrainte de cardinalité : couple $(\text{min}, \text{max})$ qui représente le nombre minimum/maximum de fois qu'une entité du type-entité peut participer au type association.
>
> La __cardinalité__ d'un type-association est le $\text{max} {\scriptsize 1} - \text{max} {\scriptsize 2}$ des contraites de cardinalité des 2 types-entité.

$\underline{\text{Exemple}}$

![image](ressources/chap_14/cardinalite.png)

- Cardinalités usuelles:
  1) $1-1$ (one to one)
  2) $1-*$ (one to many)
  3) $*-*$ (many to many)

⚠️ Les types-associations de cardinalité $*-*$ doivent être transformés en 2 types-associations $1-*$ en transformant le type-association en type-entité.

$\underline{\text{Exemple}}$

![image](ressources/chap_14/mtm_to_otm.png)

- $\underline{\textbf{1ère étape de conception d'une base:}}$
  - dessiner les types-entités et leurs propriétés.
  - dessiner les types-association et leurs propriétés.
  - binariser les types-associations si nécessaire.
  - transformer les types-associations $*-*$ en 2 $(1-*)$ .

$\to$ Modèle entité-association = point de vue utilisateur.

$\to$ Structure de données internes = point de vue SGBD.

### 3. Modèle relationnel

> __Vocabulaire__:
>
> - *relations* (tableau à 2 dimensions)
> - *attributs* (colonnes)
> - *domaine* (type (INT/REEL/TEXT), info supplémentaires de format, possibilité de ne pas être renseigné (NULL)).
> - *Enregistrement* (lignes)
> - *clés primaires* = attribut (ou groupe d'attribut) d'une relation que fait respecter la contrainte d'unicité.
> - *clés étrangères* = attrivu (ou groupe d'attributs) d'une relation qui fait référence (va chercher ses valeus) à la clé primaire d'autre relation, fait respecter la contrainte de référence
> - *Schéma relationnel*: contient relations, attributs, clés primaires et étrangères qui constituent.

- $\underline{\textbf{2ème étape de conception d'une base de données:}}$
  
  - transformer le modèe entite-association en un chéma relationnel interprétable par le SGBD.
  
  - Chaque type-entité devient une relation.
  
  - Les propriétés des types-entités deviennent des attributs.
  
  - ![image](ressources/chap_14/cercle.png) = un attribut, non NULL
  
  - ![image](ressources/chap_14/double_cercle.png) = un attribut, peut-être NULL
  
  - ![image](ressources/chap_14/cercle_pointies.png) = plusieurs attributs ou 1 dont le domaine précise l'organisation
  
  - La construction de type-entité garantit déja la présence d'un ou plusieurs attibuts pour constituer une clé primaire.
  
  - chaque type-association devient une clé étrangère, placée dans la relation ayant donné le " $1$ " à la cardinalité qui fait référence à la relation ayant donnée le " $*$ " .

$\underline{\text{Exemple}}$

![image](ressources/chap_14/ex_creation_schema.png)

$$
\text{Légende :}
\begin{cases}
\textbf{Gras} = \text{clé primaire} \\
\rightarrow \space  = \text{clé étrangère}
\end{cases}
$$

- Pays (__id__, nom, superficie)

- Ville (__id__, nom, nb_habitants, id_pays $\rightarrow$ Pays.id)

- Auteur (__id__, nom, prenom, naissance, mort, id_ville $\rightarrow$ Ville.id)

- Bibliotheque (__id__, nom, adresse, téléphone, id_ville $\rightarrow$ Ville.
id)

- Livre (__isbn__, titre , annee, id_auteur $\rightarrow$ Auteur.id)

- Inventaire (__id__, nb_exemplaires, isbn_livre $\rightarrow$ Livre.isbn, id_biblio $\rightarrow$ Bibliotheque.id)
