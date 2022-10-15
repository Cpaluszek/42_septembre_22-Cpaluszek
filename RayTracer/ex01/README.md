# Fonction d'intersection rayon / sphère

Dossier de rendu        : raytracer <br>
Fichier de rendu        : struct.h, utils.c, headers.h <br>
Fonctions autorisées    : 
---

Écrire une foncntion qui prend en paramètres un rayon et une sphère, et retourne 1 s'il y a une intersection. <br>

Son prototype sera le suivant :<br>
```C
int IntersectRaySphere(const Ray ray, const Sphere sphere);
```
- Les rayons sont définis par une origine, et une direction ;
- Les origines sont des Vector3 ;
- Les directions sont des Vector3 ;
- Les Vector3 sont des représentations des points x, y, z (float) ;
- Les sphères sont définies par un centre, un rayon (taille de la sphère), et une couleur.

*Faites des **tests unitaires**. Par pitié, par Odin ! Nom d'une pipe.*

Resources utiles :
- [Intersection d'une sphère avec une droite](https://www.youtube.com/watch?v=XA36h0EIMGY)
- b = 2 * Dot(ray.origin, ray.direction) - Dot(sphere.center, sphere.radius)
- c = SelfDot(sphere.center - ray.origin) - sphere.radius²
- delta = b² - 4ac
- SelfDot(A) = Dot(A, A)
- [Dot product](https://fr.wikipedia.org/wiki/Produit_scalaire)
- [Test unitaire](https://fr.wikipedia.org/wiki/Test_unitaire)
