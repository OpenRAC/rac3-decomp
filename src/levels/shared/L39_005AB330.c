#include "common.h"

/* localdecomp:start func_L39_005AB330 */
extern void func_0038CBA0(void *buf, int size);

extern void func_0038CC88(void *target, void *base, int len);

extern int func_001264E0(int code);

/* The record the table entry points at: three shorts and an array of 64-bit slots. */
typedef struct L110E8Rec {
    char          pad00[0x06];
    short         f06;
    char          pad08[2];
    short         f0A;
    char          pad0C[2];
    short         f0E;
    unsigned long slots[1];
} L110E8Rec;

/* What the function writes: five shorts and the same array of 64-bit slots. */
typedef struct L110E8Out {
    char          pad00[0x06];
    short         f06;
    short         f08;
    short         f0A;
    short         f0C;
    short         f0E;
    unsigned long slots[1];
} L110E8Out;

/* The object the two table pointers come from. */
typedef struct L110E8Src {
    char          pad00[0x14];
    char         *f14;
    char         *f18;
} L110E8Src;



/* from rac2-decomp's func_L00_003110E8, renamed */
void func_L39_005AB330(L110E8Src *a0, int a1, int a2, L110E8Out *a3)
{
    char *p18 = a0->f18;
    char *p14 = a0->f14;
    unsigned char n3 = (unsigned char)p18[8];
    unsigned char n0 = (unsigned char)p14[8];
    int *q;
    L110E8Rec *rec;
    unsigned short *uf;
    unsigned short uhA;
    unsigned short uhE;
    L110E8Out *out = a3;
    short hA;
    short hE;
    int destinationOffset;
    int v;
    int len;

    p18 += a1 * 4;
    q = *(int **)(p18 + 0x48);
    q += a2;
    rec = ((L110E8Rec **)q)[7];
    uf = (unsigned short *)rec;
    func_0038CBA0(out, ((n0 + 3) * 8) & 0xFF0);

    destinationOffset = n0 * 8;
    {
        char *msrc = (char *)rec + (n3 * 8 + 0x10);

        hA = rec->f0A;
        hE = rec->f0E;
        out->f08 = (short)destinationOffset;
        v = n0 + hA;
        v += hE;
        v += 1;
        out->f06 = (short)(v >> 1);
        uhA = uf[5];
        out->f0A = uhA;
        out->f0C = (short)((uhA + n0) * 8);
        uhE = uf[7];
        out->f0E = uhE;

        len = rec->f06 * 16 - n3 * 8;
        if (len != 0)
            func_0038CC88((char *)out + (destinationOffset + 0x10), msrc, len);
    }

    {
        unsigned char *table = (unsigned char *)(*(int *)(a0->f18 + 0x1C)) + 4;
        int i;
        unsigned long *src = (unsigned long *)((char *)rec + 0x10);

        if (n3 != 0) {
            i = n3;

            while (i != 0) {
                *(unsigned long *)((char *)out + table[0] * 8 + 0x10) = src[0];
                table++;
                src++;
                i--;
            }
        }
    }
    {
        unsigned long *p = (unsigned long *)((char *)out + out->f06 * 16);

        if (*p == 0)
            *p = 1;
    }
    func_001264E0(0);
}
/* localdecomp:end func_L39_005AB330 */
