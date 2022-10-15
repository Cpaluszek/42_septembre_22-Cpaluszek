# Crée une image a partir d'un tableau de pixels

Dossier de rendu        : raytracer <br>
Fichier de rendu        : camera.c, struct.h, utils.c (si besoin), headers.h (si besoin)<br>
Fonctions autorisées    : open, close, write
---

Écrire une fonction qui prend en paramètres un tableau de pixels a 2 
dimensions ainsi que sa taille, et écrit une image ppm à partir de ce 
tableau.<br>

Son prototype sera le suivant :<br>
```C
void save_ppm(int width, int height, Pixel **pixels);
```
- Les pixels sont constitués de Color
- Les colors r, g, b sont des ints entre 0 et 255

Vous pouvez tester votre image avec ce tableau de pixels
```C
Pixel **pixels;
pixels = (Pixel **)malloc(sizeof(Pixel *) * height);
for (int i = 0; i < height; i++)
{
    pixels[i] = (Pixel *)malloc(sizeof(Pixel) * width);
}
pixels[0][0].color.red = 255;
pixels[0][0].color.green = 0;
pixels[0][0].color.blue = 0;
pixels[0][1].color.red = 0;
pixels[0][1].color.green = 255;
pixels[0][1].color.blue = 0;
pixels[0][2].color.red = 0;
pixels[0][2].color.green = 0;
pixels[0][2].color.blue = 255;
pixels[1][0].color.red = 255;
pixels[1][0].color.green = 255;
pixels[1][0].color.blue = 0;
pixels[1][1].color.red = 255;
pixels[1][1].color.green = 255;
pixels[1][1].color.blue = 255;
pixels[1][2].color.red = 0;
pixels[1][2].color.green = 0;
pixels[1][2].color.blue = 0;
```

Resources utiles :
- [Image PPM](https://fr.wikipedia.org/wiki/Portable_pixmap#PPM)
