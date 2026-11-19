/* functional: high. Rewritten from the PAL boot_elf assembly (the nonmatching draft is a US rac3-uya-decomp port and was not used). Retail's two lqc2/vadd.xyz/sqc2 sums are written as plain C (xyz added, w kept from the first operand); register allocation differs. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C0268;
typedef struct { f32 u, v; } UV_003C0268;
typedef struct { u8 pad[8]; u8 b8; } O_003C0268;

extern s32 D_001D8ED8_bfC268;
extern s32 D_001D8EDC_bfC268;
extern V4_003C0268 D_001D8EF0_bfC268;
extern V4_003C0268 D_001D8F00_bfC268[];
extern s32 D_001D8EC0_bfC268;
extern s32 D_001D8EC4_bfC268;
extern s32 D_001D8EC8_bfC268;
extern s32 D_001D8ECC_bfC268;
extern f32 D_001D8ED0_bfC268;
extern f32 D_001D8ED4_bfC268;
extern f32 D_001D8EE0_bfC268;
extern V4_003C0268 D_001D8F10_bfC268[4];
extern UV_003C0268 D_001D8F50_bfC268[4];
extern UV_003C0268 D_001D8F70_bfC268[4];
extern s32 D_001D9D00_bfC268[];
extern V4_003C0268 D_003800C0_bfC268[];
extern O_003C0268 *D_001DA318_bfC268[];
extern UV_003C0268 D_001DA390_bfC268[];
extern s32 D_001DA378_bfC268[];
extern u8 D_001DA348_bfC268[];
extern f32 D_001DA340_bfC268[];
extern u8 D_00222420_bfC268[];
extern V4_003C0268 D_00222400_bfC268[];

extern void func_003A97F8(s32, unsigned long);
extern void func_0038CB30(void);
extern void func_003C3278();
extern s32 func_00382848();
extern void func_0038D408();
extern void func_0038D3E0(void *, void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_0038D068();
extern long func_00389978(s32);
extern void func_003D3DDC();
extern f32 func_0038D2E0(void *, void *);
extern void func_00389858(void *, f32 *, f32 *);

/* Draws six light-beam/sparkle quads around an object (boot_elf front-end): for each of the
 * six anchor points D_003800C0[i] and each of D_001D8EDC phases, a quad whose size and
 * colour pulse with the phase (frame D_001D9D00), drawn twice (add and blend passes). */
void func_003C0268(void *obj) {
    V4_003C0268 mtx[4];      /* sp+0x80 */
    V4_003C0268 base;        /* sp+0x00 */
    V4_003C0268 off;         /* sp+0x10 */
    V4_003C0268 corner;      /* sp+0x20 */
    V4_003C0268 centre;      /* sp+0x30 */
    V4_003C0268 quad[4];     /* sp+0x40 */
    s32 start;
    s32 i;

    func_003A97F8(8, 5);
    func_003A97F8(0x14, 0x0000FF9000000260UL);
    func_003A97F8(0x47, 0x513F1);
    func_0038CB30();
    {
        s32 n = D_001D8ED8_bfC268;
        s32 q = n / D_001D8EDC_bfC268;
        s32 t = D_001D9D00_bfC268[0];
        start = t + (((t + q) % n) / q) * q;
    }
    func_003C3278(obj, 0, mtx);

    i = 0;
    do {
        V4_003C0268 *anchor;
        s32 j;
        u8 c = func_00382848(0xFF);
        anchor = &D_003800C0_bfC268[i];
        D_001DA318_bfC268[i + 1]->b8 = c;
        func_0038D408(&base, anchor, mtx);
        i++;
        if (D_001D8EDC_bfC268 > 0) {
            j = 0;
            do {
                s32 n = D_001D8ED8_bfC268;
                s32 q = n / D_001D8EDC_bfC268;
                f32 ph = (f32)((start + q * j) % n) / (f32)n;
                f32 sz;
                s32 col;
                s32 k;

                j++;
                if (0.0f < anchor->y) {
                    func_0038D3E0(&off, &D_001D8EF0_bfC268, mtx);
                } else {
                    func_0038D3E0(&off, D_001D8F00_bfC268, mtx);
                }
                func_0038D200((f32 *)&off, &off, ph);
                centre.x = base.x + off.x;
                centre.y = base.y + off.y;
                centre.z = base.z + off.z;
                centre.w = base.w;
                col = func_0038DFB8(D_001D8EC0_bfC268, D_001D8EC4_bfC268, ph);

                for (k = 0; k < 4; k++) {
                    f32 s;
                    corner = D_001D8F10_bfC268[k];
                    s = D_001D8EE0_bfC268 * ph + 1.0f;
                    D_001DA378_bfC268[k] = col;
                    corner.y = corner.y * s;
                    corner.z = corner.z * s;
                    func_0038D3E0(&quad[k], &corner, D_00222420_bfC268);
                    func_0038D200((f32 *)&quad[k], &quad[k], D_001DA340_bfC268[0]);
                    quad[k].x = quad[k].x + centre.x;
                    quad[k].y = quad[k].y + centre.y;
                    quad[k].z = quad[k].z + centre.z;
                    func_0038D068(D_001DA348_bfC268 + k * 12, &quad[k], 12);
                    D_001DA390_bfC268[k] = D_001D8F50_bfC268[k];
                }
                func_003A97F8(6, func_00389978(0x16));
                func_003A97F8(0x42, 0x800000006AUL);
                func_003D3DDC(4, D_001DA348_bfC268, D_001DA378_bfC268, D_001DA390_bfC268, 1);

                sz = D_001D8ED0_bfC268 * (1.0f / (func_0038D2E0(&centre, D_00222400_bfC268) + 1.0f));
                if (D_001D8ED4_bfC268 < sz) {
                    sz = D_001D8ED4_bfC268;
                } else if (sz < -D_001D8ED4_bfC268) {
                    sz = -D_001D8ED4_bfC268;
                }
                col = func_0038DFB8(D_001D8EC8_bfC268, D_001D8ECC_bfC268, ph);
                for (k = 0; k < 4; k++) {
                    D_001DA378_bfC268[k] = col;
                    func_00389858(&quad[k], &D_001DA390_bfC268[k].u, &D_001DA390_bfC268[k].v);
                    D_001DA390_bfC268[k].u = D_001DA390_bfC268[k].u + D_001D8F70_bfC268[k].u * sz;
                    D_001DA390_bfC268[k].v = D_001DA390_bfC268[k].v + D_001D8F70_bfC268[k].v * sz;
                }
                func_003A97F8(6, func_00389978(-1));
                func_003A97F8(0x42, 0x8000000054UL);
                func_003D3DDC(4, D_001DA348_bfC268, D_001DA378_bfC268, D_001DA390_bfC268, 1);
            } while (j < D_001D8EDC_bfC268);
        }
    } while (i < 6);

    func_003A97F8(8, 0);
    func_003A97F8(0x47, 0x5360B);
}
