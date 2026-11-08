/* Ported from rac4-decomp's func_0053C920 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
typedef struct { unsigned a:4; unsigned b:6; unsigned c:4; unsigned rest:18; int pad; int f8; char pad2[68]; int f50; char f54; char f55; } Type1;
extern Type1 *func_L39_006629F8(void);
extern void func_L39_00662B68(Type1 *, int, int);
extern int D_001A5CD8[];

Type1 *func_L39_006625A8(int *arg0, int arg1, int arg2, int arg3) {
 Type1 *p = func_L39_006629F8();
 p->a = arg1;
 p->f8 = *arg0;
 p->b = 0;
 p->c = D_001A5CD8[0];
 p->f54 = 0;
 p->f50 = -1;
 p->f55 = 1;
 func_L39_00662B68(p, arg2, arg3);
 return p;
}