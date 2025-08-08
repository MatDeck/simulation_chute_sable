# ⏳ Simulation de Chute de Sable 

Ce projet est une simulation graphique de chute de sable et autres matériaux, réalisée en **C++** avec la bibliothèque **SFML**, dans le cadre d’un projet réaliser en cours.

---

## 🧰 Technologies utilisées

- **Langage** : C++
- **Bibliothèque graphique** : [SFML 2.6.2]

---

## 🎮 Fonctionnalités principales

- 📐 Interface graphique SFML avec une grille paramétrable
- 🎨 Dessin de matériaux à la souris
- ⏯️ Simulation en temps réel
- 🔁 Interaction dynamique entre les éléments
---


## ⚙️ Comportement des matériaux

Chaque matériau possède un comportement propre au sein de la simulation :

- ⏳ **Sable** (`S`, Jaune)  
  Tombe verticalement si la case en dessous est vide. Si bloqué, il essaie de glisser en diagonale vers la gauche ou la droite.

- 🪨 **Pierre** (`P`, Blanc)  
  Solide et statique. Ne bouge pas et bloque les matériaux mobiles.

- ⚫ **Vide** (`V`, Noir)  
  Représente une cellule vide. Permet le déplacement des matériaux.

- 🔩 **Acier** (`A`, Gris foncé)  
  Solide et **résistant à l’acide**. Ne bouge pas et ne peut pas être corrodé.

- 🧪 **Acide** (`C`, Vert)  
  Descend verticalement si possible. Sinon, tente d’aller à droite, puis à gauche. Corrode les matériaux sensibles. Une cellule sensible exposée trop longtemps est détruite avec l’acide.


## 🕹️ Commandes clavier et souris

| Touche | Matériau sélectionné     | Couleur dans la simulation |
|--------|---------------------------|-----------------------------|
| `S`    | Sable                     |  Jaune                    |
| `P`    | Pierre                    |  Blanc                    |
| `V`    | Vide                      |  Noir                     |
| `A`    | Acier                     |  Gris foncé              |
| `C`    | Acide                     |  Vert                     |

- **Clic gauche** : Dessine le matériau sélectionné à la position du curseur.
- **Fermeture fenêtre** : Cliquez sur la croix ou appuyez sur `Esc`.

---

