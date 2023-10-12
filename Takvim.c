#include <stdio.h>
#include <stdlib.h>


int ilkGun(int );

int main()
{

    int yil, gun = 0, gun_sayisi, haftanin_gunu = 0, baslangic_gunu, ay;
    int i;
    char *aylar[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
    int ay_gunleri[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    baslangic_gunu = ilkGun(yil);

    printf("Yil Giriniz: ");
    scanf("%d", &yil);

    if ((yil % 4 == 0 && yil % 100 != 0) || yil % 400 == 0)
    {
        ay_gunleri[1] = 29;
    }

    for (i=0;i<12;i++)
    {
        gun_sayisi = ay_gunleri[i] + 1;
        printf("\n\n-----%s-----\n", aylar[i]);
        printf("  Pzt  Sal  Car  Per  Cum  Cmt  Paz\n");


        for (haftanin_gunu = 0; haftanin_gunu < baslangic_gunu; haftanin_gunu++)
        {
            printf("     ");
        }

        for (gun = 1; gun < gun_sayisi; gun++)
        {
            printf("%5d", gun);
            if (++haftanin_gunu > 6)
            {
                printf("\n");
                haftanin_gunu = 0;
            }

            baslangic_gunu = haftanin_gunu;
        }
    }

    return 0;
}
int ilkGun(int yil)
{
    int gun;
    gun = (((yil - 1)*365) + ((yil - 1) / 4) - ((yil - 1) / 100) + ((yil) / 400) + 0) % 7;
    return gun;
}
