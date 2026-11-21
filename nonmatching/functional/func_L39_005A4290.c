/* functional: high. Level-data loader (levels 39-53): turns the level image's section offsets into pointers and fills the level tables. Compiles at level 39 (580 diff vs retail: register allocation/order only); same reads, writes and calls in the same order; 2nd parameter unused as in retail; GS packet words are folded constants. */
#include "vu0.h"

typedef struct {
    int f00, f04, f08;
    char *data;                 /* 0x0C: the level data image */
    int f10, f14;
    char *heap;                 /* 0x18: running heap pointer */
    char *f1C, *f20, *f24, *f28;
    char *f2C, *f30, *f34, *f38, *f3C, *f40, *f44;
    char *f48;
    char pad4C[0x1C];
    int f68;
} Ctx_5A4290;

typedef struct {
    int f0;
    char *f4;
    char *f8;
    int fC;
    char *f10;
    char *f14;
    int f18;
} Tut_5A4290;

typedef struct {
    char pad0[0xD];
    unsigned char count;        /* 0x0D */
    char pad0E[0x1A];
    char *elems;                /* 0x28: 0x20-byte elements */
} Obj_5A4290;

typedef struct { char pad0[0x1A]; short h1A; int i1C; } Elem_5A4290;

extern Ctx_5A4290 D_L39_0025F680;
extern Tut_5A4290 D_L39_00268BC0;
extern int *D_L39_00240290;
extern int D_L39_002412DC;
extern char D_L39_0024BDE0[];
extern char D_002142D0[];
extern int D_001FC450[];
extern long D_L39_0024BDF0[3];
extern long D_L39_0024BE08[3];
extern int D_L39_002B9640[];
extern int D_L39_00274830[];
extern int D_L39_002C0F40[];
extern int D_L39_002B7BA0[];
extern int D_L39_0025F6AC;
extern int D_L39_0024C3A8;
extern int D_L39_0024B94C;
extern int D_L39_0024C428;
extern int D_L39_0024C30C;
extern char *D_L39_0024BB80;
extern int D_L39_0024C920;
extern Obj_5A4290 *D_L39_00271B40[];
extern int D_L39_00293A60;
extern unsigned char D_L39_00272590[];
extern int D_L39_00275030[];
extern short D_L39_002723B0[];
extern char *D_L39_002BA440[];
extern char *D_L39_002B6A20[];
extern char *D_L39_0024BA04;
extern int D_L39_0024B860;
extern char D_L39_0024BE20[], D_L39_0024BE30[], D_L39_0024BE40[], D_L39_0024BE50[];
extern char *D_L39_0024BB84;
extern char *D_L39_0024BB88;
extern char *D_L39_0024BB8C;
extern int D_L39_0024291C;
extern int *D_L39_0024BC8C;
extern int D_L39_0024C9A4;
extern char *D_L39_0024BB6C;
extern int D_L39_0024BB68;
extern int D_L39_0024BC20;
extern int D_L39_0024C4E0;

extern void func_L39_0059F5F8(void);
extern void func_L01_004B32E8(void);
extern void func_0038CD28(void *, void *, int);
extern void func_0038CC88(void *, void *, int);
extern void func_L39_0059FC80(void *, int, int, void *);
extern void func_001264E0(int);
extern int func_003A0760(void *, void *);
extern void func_L39_005A0DB0(void *, void *);
extern void func_00398668(void *);
extern void func_L01_00427E58(void *);
extern void func_00399D68(void *, void *, void *, int);
extern void func_L01_00427F18(void *, int, void *);
extern void func_L39_0057CCC0(void);
extern void func_L39_005A0440(void *, void *, void *, int);
extern void func_L01_003EDD80(void *, int);
extern void func_L39_005A0818(void *, void *, void *, void *, int);
extern void func_003985B8(void *, int);
extern void func_L01_00425218(void *);
extern void func_00398498(void *, void *, void *, int);
extern int func_L39_005A12B8(int);
extern void func_L01_0042AE30(void);
extern void func_L01_0042AF50(int);
extern void func_L01_003F1E98(int);

int func_L39_005A4290(int load, int unused) {
    int *hdr = D_L39_00240290;
    char *img;
    char *heap;
    char *end;
    int *i;                     /* image header, words */
    int n, k, j;
    int *p;
    int *dst;
    char *q70, *q;
    short *sp;
    long a, b;
    char *base;

    img = D_L39_0025F680.data;
    if (load != 0) {
        func_L39_0059F5F8();
    }
    i = (int *)img;
    heap = D_L39_0025F680.heap;
    if (load != 0) {
        char *hp;
        int r;

        func_L01_004B32E8();
        D_L39_00268BC0.f0 = 0;
        func_0038CD28(img, (char *)hdr + hdr[2], hdr[3]);
        func_0038CC88(D_L39_0024BDE0, D_002142D0 + (D_L39_002412DC << 4), 0x10);
        func_L39_0059FC80((char *)hdr + hdr[4], i[0], i[0x84 / 4], img + i[1]);
        func_001264E0(0);
        r = func_003A0760((char *)hdr + hdr[0x48 / 4], heap);
        hp = heap + r;
        D_L39_0025F680.f2C = heap + i[0x60 / 4];

        a = (D_001FC450[0x20 / 4] + i[0x94 / 4]) >> 8;
        b = (D_001FC450[0x34 / 4] + (i[0x90 / 4] << 2)) >> 8;
        D_L39_0024BDF0[0] = ((a << 37) | 0x5C0000000L) | (b | 0x1DB08000L) | 0x8000000000000000L;
        D_L39_0024BDF0[1] = 0xFFA0000000E0L;
        D_L39_0024BDF0[2] = 0x40000400004000L;
        a = (D_001FC450[0x20 / 4] + i[0x9C / 4]) >> 8;
        b = (D_001FC450[0x34 / 4] + (i[0x98 / 4] << 2)) >> 8;
        D_L39_0024BE08[0] = ((b | 0x19B04000L) | ((a << 37) | 0x580000000L)) | 0x8000000000000000L;
        D_L39_0024BE08[1] = 0xFFA0000000E0L;
        D_L39_0024BE08[2] = 0x40000400004000L;

        n = i[0x30 / 4];
        D_L39_0024C3A8 = n;
        if (n > 0) {
            p = (int *)(img + i[0x34 / 4]);
            dst = D_L39_002B9640;
            base = D_L39_0025F680.f2C;
            for (; n > 0; n--, p += 4) {
                *dst++ = (int)base + p[0] + ((30 - plzcw_asm(*(unsigned short *)(p + 1))) << 28);
            }
        }
        n = i[0x38 / 4];
        D_L39_0024B94C = n;
        if (n > 0) {
            p = (int *)(img + i[0x3C / 4]);
            dst = D_L39_00274830;
            for (; n > 0; n--, p += 4) {
                *dst++ = D_L39_0025F6AC + p[0] + ((30 - plzcw_asm(*(unsigned short *)(p + 1))) << 28);
            }
        }
        n = i[0x40 / 4];
        D_L39_0024C428 = n;
        if (n > 0) {
            p = (int *)(img + i[0x44 / 4]);
            dst = D_L39_002C0F40;
            for (; n > 0; n--, p += 4) {
                *dst++ = D_L39_0025F6AC + p[0] + ((30 - plzcw_asm(*(unsigned short *)(p + 1))) << 28);
            }
        }
        n = i[0x48 / 4];
        D_L39_0024C30C = n;
        if (n > 0) {
            p = (int *)(img + i[0x4C / 4]);
            dst = D_L39_002B7BA0;
            for (; n > 0; n--, p += 4) {
                *dst++ = D_L39_0025F6AC + p[0] + ((30 - plzcw_asm(*(unsigned short *)(p + 1))) << 28);
            }
        }

        D_L39_0025F680.f1C = heap + i[2];
        func_L39_005A0DB0(D_L39_0025F680.f1C, img + i[0x34 / 4]);
        D_L39_00268BC0.f8 = D_L39_0025F680.f1C;
        if (i[3] != 0) {
            D_L39_0025F680.f20 = heap + i[3];
            D_L39_0024BB80 = D_L39_0025F680.f20;
        } else {
            D_L39_0025F680.f20 = 0;
            D_L39_0024BB80 = 0;
        }
        if (i[4] != 0) {
            D_L39_0025F680.f24 = heap + i[4];
            func_00398668(D_L39_0025F680.f24);
        } else {
            D_L39_0024C920 = 0;
            D_L39_0025F680.f24 = 0;
        }
        D_L39_0025F680.f28 = heap + i[5];
        func_L01_00427E58(D_L39_0025F680.f28);
        D_L39_00268BC0.f4 = D_L39_0025F680.f28;

        q = img + i[7];
        for (k = 0; k < i[6]; k++, q += 0x20) {
            int off = *(int *)q;
            func_00399D68(off != 0 ? heap + off : 0, img + i[0x3C / 4], q + 0x10, *(int *)(q + 4));
        }
        D_L39_0025F680.f38 = (char *)D_L39_00271B40[0];
        func_L01_00427F18(img + i[7], i[6], img + i[9]);
        func_L39_0057CCC0();
        D_L39_00293A60 = 0;

        sp = (short *)(img + i[0xAC / 4]);
        if (*sp >= 0) {
            do {
                unsigned char t = D_L39_00272590[*sp];
                if (t != 0xFF) {
                    D_L39_00275030[t] = 0xFFF00000;
                }
                sp++;
            } while (*sp >= 0);
        }

        q = img + i[9];
        for (k = 0; k < i[8]; k++, q += 0x20) {
            func_L39_005A0440(heap + *(int *)q, img + i[0x44 / 4], q + 0x10, *(int *)(q + 4));
        }
        if (D_L39_002BA440[0] != 0) {
            D_L39_0025F680.f3C = D_L39_002BA440[0];
        }
        func_L01_003EDD80(img + i[9], i[8]);
        q = img + i[0xB];
        for (k = 0; k < i[0xA]; k++, q += 0x30) {
            func_L39_005A0818(heap + *(int *)q, img + i[0x4C / 4], q + 0x10, q + 0x20, *(int *)(q + 4));
        }
        if (D_L39_002B6A20[0] != 0) {
            D_L39_0025F680.f40 = D_L39_002B6A20[0];
        }
        D_L39_0025F680.f34 = heap + i[0x68 / 4];
        D_L39_0024BA04 = D_L39_0025F680.f34;
        func_003985B8(img + i[0x5C / 4], i[0x58 / 4]);
        if (i[0xA4 / 4] == 0) {
            D_L39_0024B860 = 0;
            qzero(D_L39_0024BE20);
            qzero(D_L39_0024BE30);
            qzero(D_L39_0024BE40);
            qzero(D_L39_0024BE50);
        } else {
            func_L01_00425218(heap + i[0xA4 / 4]);
        }
        D_L39_0024BB84 = i[0xA8 / 4] != 0 ? heap + i[0xA8 / 4] : 0;
        D_L39_0024BB88 = i[0xB0 / 4] != 0 ? heap + i[0xB0 / 4] : 0;
        D_L39_0024BB8C = i[0xB8 / 4] != 0 ? heap + i[0xB8 / 4] : 0;
        if (i[0xB4 / 4] != 0) {
            int *t = (int *)(heap + i[0xB4 / 4]);
            n = t[0];
            D_L39_0024291C = n;
            D_L39_0024BC8C = t + 2;
            if (n > 0) {
                char *rel = (char *)t + t[1];
                int *e = t + 2;
                for (; n > 0; n--, e += 4) {
                    e[1] += (int)rel;
                }
            }
        } else {
            D_L39_0024BC8C = 0;
        }
        D_L39_0025F680.f30 = heap + i[0x64 / 4];
        func_00398498(img + i[0x6C / 4], D_L39_0025F680.f30, img + i[0x54 / 4], i[0x50 / 4]);

        heap = (char *)(((int)hp + 0x3F) & ~0x3F);
        end = heap;
        if (D_L39_0024C9A4 != D_L39_00268BC0.f18) {
            int sz = i[0x30 / 4] << 4;
            D_L39_00268BC0.f10 = heap;
            func_0038CD28(heap, img + i[0x34 / 4], sz);
            heap += sz;
            D_L39_00268BC0.f14 = heap;
            heap = (char *)(((int)heap + (D_L39_00268BC0.f18 << 1) + 0x7F) & ~0x3F);
        }
        q70 = img + i[0x70 / 4];
        D_L39_0024BB6C = heap;
        D_L39_0024BB68 = *(short *)(q70 + 2);
        k = *(short *)(q70 + 2) << 5;
        func_0038CC88(heap, q70 + *(short *)q70, k);
        q = q70 + 4;
        heap += k;
        base = q70 + *(short *)q;
        if (D_L39_0024BB68 > 0) {
            char *e = D_L39_0024BB6C;
            for (n = D_L39_0024BB68; n != 0; n--, e += 0x20) {
                Elem_5A4290 *el = (Elem_5A4290 *)(e);
                int idx = el->h1A;
                if (idx < *(short *)(q + 2)) {
                    el->h1A = *(unsigned short *)(base + (idx << 2));
                } else {
                    el->h1A = -1;
                }
                el->i1C = 0;
            }
        }
        end = heap + 0x3F;
        q += 4;
        n = i[6];
        p = (int *)(img + i[7]);
        if (n > 0) {
            for (k = 0; k < i[6]; k++, p += 8, q += 4) {
                int key = p[1];
                unsigned char b8 = D_L39_00272590[key];
                if (D_L39_002723B0[b8] == key) {
                    Obj_5A4290 *o = D_L39_00271B40[b8];
                    int *src = (int *)(q70 + *(short *)q);
                    int cnt = src[0];

                    if (o->count != 0) {
                        short *hs = (short *)(src + 1);
                        for (j = 0;;) {
                            Elem_5A4290 *el = (Elem_5A4290 *)(D_L39_00271B40[b8]->elems + (j << 5));
                            j++;
                            el->h1A = *(unsigned short *)hs;
                            el = (Elem_5A4290 *)(D_L39_00271B40[b8]->elems + ((j - 1) << 5));
                            el->i1C = cnt + 1;
                            if (!(j < D_L39_00271B40[b8]->count)) {
                                break;
                            }
                            hs += 2;
                        }
                    }
                }
            }
        }
        heap = (char *)(((int)end) & ~0x3F);
        D_L39_0025F680.f48 = heap;
    }
    D_L39_0025F680.f68 = func_L39_005A12B8(load);
    if (D_L39_00268BC0.fC != 0) {
        if (load != 0) {
            func_L01_0042AE30();
        }
        func_L01_0042AF50(D_L39_00268BC0.f0);
    }
    D_L39_0024BC20 = 0;
    D_L39_0024C4E0 = 0;
    func_L01_003F1E98(1);
    return 0;
}
