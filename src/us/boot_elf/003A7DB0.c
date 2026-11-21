#include "common.h"

/* NTSC-U version of func_003A7EF8 (boot_elf): 50 -> 60; 50 -> 60; 50 -> 60 */
#include "common.h"


typedef int u128_t __attribute__((mode(TI)));



#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6578;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_160C40 D_160C40;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x34 - 0x21]; u16 f34; u8 pad36[0xAA - 0x36]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3A1438;
typedef struct {
    u8 pad[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x60 - 0x4A]; s8 f60; u8 pad61[0x1A0 - 0x61]; O_3A1438 *f1A0[1];
} S_225780_3A1438;
typedef struct { u8 pad[0x1A0]; unsigned long f1A0; } Pad_3A1438;
typedef struct { u8 pad[0x25C0]; O_3A1438 *f25C0; } S_1A4BE0_3A1438;
extern void func_U_0038D148_003A6C90(void *, void *, f32);
#include "vu0.h"
extern void func_U_003A7DB0();
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870 *f1A0[1];
} S_225780_3A1870;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870_003A70C8;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870_003A70C8;
typedef struct {
    u8 pad[0x24]; T_3A1870_003A70C8 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870_003A70C8;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870_003A70C8 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870_003A70C8 *f1A0[1];
} S_225780_3A1870_003A70C8;
extern void func_11F0A0(s32);
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_3A1AD0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_3A1AD0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_3A1AD0 r[1]; } S_160C40_3A1AD0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_3A1AD0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_3A1AD0;
extern S_160C40_3A1AD0 D_160C40_003A7328;
extern S_1CCFD0_3A1AD0 D_1CCFD0_003A7328;
extern u32 D_142BA0[];
extern u8 D_1A5DC0[];
extern s32 D_U_001D5B94;
extern s32 func_12C908(s32);
typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern s32 func_12C908(s32);
extern void func_13B620_003A76A0(void);
typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern s32 D_U_001D5B94;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x14]; s32 f4C; } S_225780_3A21C0;
extern u8 D_13D208[];
extern s32 D_U_001D5B94;
extern void func_13CF80(s32, s32, s32, s32, s32);
extern s32 func_12C908(s32);
extern void func_11F0A0(s32);
extern long func_13CDF0_003A7A18(s32);
extern s32 func_13CD28(s32, s32, s32, void *);
extern s32 func_12A9F0(s32, s32);
extern void func_12D4D8(u8 *);
typedef struct { u8 pad[0x90]; s32 slot[6]; } S_003A7CB8;
extern void func_11F0A0(s32);
extern void func_13CF80(s32,s32,s32,s32,s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern s32 func_12C908(s32);
extern long func_13CDF0_003A7A18(s32);
/* localdecomp:start func_U_003A7DB0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A7EF8;
typedef union { u128_t q; V_003A7EF8 v; } Q_003A7EF8;
typedef struct { f32 u, v; } UV_003A7EF8;
typedef struct { Q_003A7EF8 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } P_003A7EF8;
typedef struct { s16 i; s16 pad; } I_003A7EF8;
typedef struct { u8 pad[0x140]; f32 x, y; } C_003A7EF8;
typedef struct { u8 pad[0x10]; f32 x, y; } O_003A7EF8;
__asm__(".extern D_U_001D5B94_003A7EF8, 16");
extern s32 D_U_001D5B94_003A7EF8;
__asm__(".extern D_U_001D6EE0, 4");
extern s32 D_U_001D6EE0;
__asm__(".extern D_U_001D6EE4, 4");
extern s32 D_U_001D6EE4;
__asm__(".extern D_U_001D6EE8, 4");
extern s32 D_U_001D6EE8;
extern s16 D_0016C5A0[];
extern C_003A7EF8 D_U_00222340_003A7EF8;
extern V_003A7EF8 D_U_00222480_003A7EF8;
extern Q_003A7EF8 D_U_0022DA40[];
extern UV_003A7EF8 D_U_0022DCF0[];
extern UV_003A7EF8 D_U_0022DE48[];
extern V_003A7EF8 D_U_00334450[];
extern V_003A7EF8 D_U_00334960[];
extern I_003A7EF8 D_U_00334700[][4];
extern long func_U_00389920(s32);
extern void func_U_003C3160(u8 *, s32, u8 *);
extern s32 func_U_0038CDF8(void *);
extern void func_U_0038D350(void *, void *, void *);
extern void func_U_0038D290(void *, void *, f32);
extern f32 func_U_0038D190(void *, void *);
extern void func_U_003D2FF0(void *, s32, s32);
void func_U_003A7DB0(void *arg) {
    P_003A7EF8 q;
    V_003A7EF8 mtx[4];
    V_003A7EF8 nrm_w;
    V_003A7EF8 ref;
    V_003A7EF8 eye;
    V_003A7EF8 *verts;
    V_003A7EF8 *norms;
    I_003A7EF8 (*quads)[4];
    s32 nverts;
    s32 nquads;
    s32 col;
    s32 show;
    s32 i;
    s32 j;
    f32 blend;
    f32 m;
    f32 u;
    long tex;

    nverts = 43;
    nquads = 38;
    verts = D_U_00334450;
    norms = D_U_00334960;
    quads = D_U_00334700;
    tex = func_U_00389920(0x15);
    col = 0x3CA5A281;
    if (D_U_001D5B94_003A7EF8 == 2) col = 0x28A5A281;
    q.f80 = 0xFF9000000260UL;
    q.f78 = tex;
    q.f88 = 0x8000000044UL;
    q.f70 = 0;
    q.col[3] = col;
    q.col[2] = col;
    q.col[1] = col;
    q.col[0] = col;
    func_U_003C3160(arg, 0, (u8 *)mtx);
    show = 0;
    if (D_U_001D5B94_003A7EF8 == 0 || D_U_001D5B94_003A7EF8 == 2) {
        if (fabs_asm(D_U_00222340_003A7EF8.x - ((O_003A7EF8 *)arg)->x) < 16.0f
            && fabs_asm(D_U_00222340_003A7EF8.y - ((O_003A7EF8 *)arg)->y) < 16.0f) show = 1;
    } else {
        show = 1;
    }
    if (D_U_001D5B94 == 6 && D_0016C5A0[0] == 2) show = 0;
    if (show || D_U_001D6EE0 == 1) {
        D_U_001D6EE4 = 1;
        func_U_0038CDF8(&D_U_001D6EE8);
        blend = (f32)D_U_001D6EE8 / 60.0f;
        for (i = 0; i < nverts; i++) {
            func_U_0038D350(&D_U_0022DA40[i], &verts[i], mtx);
            vec_sub_ab(&eye, &D_U_0022DA40[i], &D_U_00222480_003A7EF8);
            func_U_0038D290(&eye, &eye, 1.0f);
            func_U_0038D350(&nrm_w, &norms[i], mtx);
            func_U_0038D290(&nrm_w, &nrm_w, 0.1f);
            func_U_0038D148_003A6C90(&ref, &nrm_w, func_U_0038D190(&nrm_w, &eye) * 2.0f);
            vec_sub_ab(&ref, &eye, &ref);
            func_U_0038D290(&ref, &ref, 1.0f);
            ref.z += 1.0f;
            m = sqrt_asm(ref.z + ref.z) * 2.0f;
            if (D_U_001D6EE0 == 1 || D_U_001D6EE8 == 0) {
                D_U_0022DCF0[i].u = ref.x / m + 0.5f;
                D_U_0022DCF0[i].v = ref.y / m + 0.5f;
            } else {
                u = ref.x / m + 0.5f;
                D_U_0022DCF0[i].u = u + (D_U_0022DE48[i].u - u) * blend;
                u = ref.y / m + 0.5f;
                D_U_0022DCF0[i].v = u + (D_U_0022DE48[i].v - u) * blend;
            }
        }
        if (D_U_001D6EE0 == 1) D_U_001D6EE0 = 2;
    } else {
        if (D_U_001D6EE4 == 1) {
            D_U_001D6EE4 = 0;
            for (i = 0; i < nverts; i++) {
                D_U_0022DE48[i].u = D_U_0022DCF0[i].u;
                D_U_0022DE48[i].v = D_U_0022DCF0[i].v;
                func_U_0038D350(&D_U_0022DA40[i], &verts[i], mtx);
            }
        } else {
            for (i = 0; i < nverts; i++) {
                func_U_0038D350(&D_U_0022DA40[i], &verts[i], mtx);
            }
        }
        D_U_001D6EE8 = 60;
    }
    for (i = 0; i < nquads; i++) {
        for (j = 0; j < 4; j++) {
            s32 k = quads[i][j].i;
            q.v[j].q = D_U_0022DA40[k].q;
            q.uv[j][0] = D_U_0022DCF0[k].u;
            q.uv[j][1] = D_U_0022DCF0[k].v;
        }
        func_U_003D2FF0(&q, 0, 0);
    }
}
/* localdecomp:end func_U_003A7DB0 */
