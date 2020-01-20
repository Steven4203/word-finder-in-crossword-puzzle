#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int a, b, Count = 0, SecondCount = 0, ThirdCount = 0, FourthCount = 0, FifthCount = 0, SixthCount = 0, SeventhCount = 0, EighthCount = 0, k, l;
    char SearchedWord[100], *ArrayPointer, *SearchPointer;

    printf("Lutfen bulmacanin uzunlugu ve genisligini aralarinda bosluk olacak sekilde giriniz |Or: 8 9|:"); /* Bulmacanin uzunlugu ve genisligini alan kisim */
    scanf("%d %d", &a, &b);

    int i, j, ArrayRow, ArrayColumn;
    char ArrayOfWord[a][b];

    ArrayPointer = ArrayOfWord;

    ArrayRow = sizeof(ArrayOfWord) / sizeof(ArrayOfWord[0]);
    ArrayColumn = sizeof(ArrayOfWord[0]) / sizeof(ArrayOfWord[0][0]);

    printf("Bulmacanin satiri:%d Bulmacanin sutunu:%d\n", ArrayRow, ArrayColumn); /* Bulmaca oncesinde gerekli bilgilerin kullaniciya verildigi kisim */
    printf("Bulmacadaki sayilar indis gosterme kolayligi sagliyor olup isteninlen harfin bulmasina herhangi bir etkide bulunmamaktadir.\n");
    printf("Lutfen aratma kismina sayi girmeyiniz.\n\n");

    srand(time(NULL));

    printf("0\t");                 /* En basta kayma yasanacagi icin sifir koymam gerekti */
    for (k = 0; k < ArrayRow; k++) /* Indislerin yazdirildigi kisim */
    {
        printf("%d\t", k);
    }
    printf("\n\n");

    for (i = 0; i < ArrayRow; i++) /* Rastgele harf verilen ve yazdirilan kisim */
    {
        printf("%d\t", i);
        for (j = 0; j < ArrayColumn; j++)
        {
            ArrayOfWord[i][j] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
            printf("%c\t", ArrayOfWord[i][j]);
        }
        printf("\n\n");
    }

    printf("NOT: Lutfen aratacaginiz kelimeyi buyuk harflerle giriniz.\n"); /* Kelimenin aratildigi kisim */
    printf("Aratmak istediginiz kelimeyi giriniz:");
    scanf("%s", &SearchedWord);

    SearchPointer = SearchedWord;

    int StringSize = strlen(SearchedWord); /* Kelime uzunlugunun alindigi kisim */

    printf("\n\n"); /* Karmasayi onlemek icin bosluk biraktim */

    /* Sadece "Soldan Saga" if inde ne yaptigimi anlattim diger dongude benzer islemler uyguladim. */

    for (i = 0; i < ArrayRow; i++) // Satir
    {
        for (j = 0; j < ArrayColumn; j++) //Sutun
        {
            if (*(*(ArrayOfWord + i) + j) == *SearchPointer) //İlk harfi aratir
            {
                if (j + StringSize <= ArrayColumn) // Soldan saga /* Satir veya sutun sonuna denk gelmemek icin bu kontrolu yapiyorum */
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i) + j + k) != *(SearchPointer + k)) /* Aranan kelime indisdeki ikinci kelimeden itibaren uyusmazlik gosterirse donguden cikartiyor */
                        {
                            break;
                        }
                        if (k == StringSize - 1) /* Son harfe kadar uyusmazlik belirlenmezse sayac arttiriliyor ve bulunan if e gore kullaniciya ilk indis soylenip nereden nereye oldugu bilgisi veriliyor */
                        {
                            Count++;
                            printf("||   Soldan saga   || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", Count, i, j);
                        }
                    }
                }
                if (i + StringSize <= ArrayRow) // Yukaridan asagi
                {
                    for (k = 0; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i + k) + j) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            SecondCount++;
                            printf("|| Yukaridan Asagi || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", SecondCount, i, j);
                        }
                    }
                }
                if (j - StringSize + 1 >= 0) // Sagdan sola
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i) + j - k) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            ThirdCount++;
                            printf("||   Sagdan Sola   || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", ThirdCount, i, j);
                        }
                    }
                }
                if (i - StringSize + 1 >= 0) // Asagidan yukari
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i - k) + j) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            FourthCount++;
                            printf("|| Asagidan yukari || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", FourthCount, i, j);
                        }
                    }
                }
                if (j + StringSize <= ArrayColumn && i + StringSize <= ArrayRow) // Sag alt capraz
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i + k) + j + k) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            FifthCount++;
                            printf("|| Sag Alt Capraz  || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", FifthCount, i, j);
                        }
                    }
                }
                if (j + StringSize <= ArrayColumn && i - StringSize + 1 >= 0) //Sag ust capraz
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i - k) + j + k) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            SixthCount++;
                            printf("|| Sag Ust Capraz  || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", SixthCount, i, j);
                        }
                    }
                }
                if (j - StringSize + 1 >= 0 && i + StringSize <= ArrayRow) //Sol alt capraz
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i + k) + j - k) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            SeventhCount++;
                            printf("|| Sol Alt Capraz  || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", SeventhCount, i, j);
                        }
                    }
                }
                if (j - StringSize + 1 >= 0 && i - StringSize + 1 >= 0) //Sol ust capraz
                {
                    for (k = 1; k < StringSize; k++)
                    {
                        if (*(*(ArrayOfWord + i - k) + j - k) != *(SearchPointer + k))
                        {
                            break;
                        }
                        if (k == StringSize - 1)
                        {
                            EighthCount++;
                            printf("|| Sol Ust Capraz  || %d.Bulunan yerin baslangic konumu - Satir:%d Sutun:%d \n", EighthCount, i, j);
                        }
                    }
                }
            }
        }
    }

    /* Toplam degerlerin kullaniciya verildigi kisim */

    printf("\n\n");
    printf("Arattiginiz deger: \t|| Toplamda %d kere ||\n\nSoldan saga    : %d \tYukaridan asagi : %d \tSagdan sola    : %d \tAsagidan yukari : %d \n", Count + SecondCount + ThirdCount + FourthCount + FifthCount + SixthCount + SeventhCount + EighthCount, Count, SecondCount, ThirdCount, FourthCount);
    printf("Sag alt capraz : %d \tSag ust capraz  : %d \tSol alt capraz : %d \tSol ust capraz  : %d kere geciyor.", FifthCount, SixthCount, SeventhCount, EighthCount);
    return 0;
}
