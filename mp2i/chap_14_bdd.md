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
