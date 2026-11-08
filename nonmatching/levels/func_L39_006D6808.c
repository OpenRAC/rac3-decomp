/* Near miss, ported from rac4-decomp's func_L00_00771D20 (cross-game near pair). NEAR: bytes exact (offset 0x44, .extern hint) but file L39_006D4ED8.c context already has conflicting D_L39_0024D760 decls from earlier localdecomps, so chk3 errors for any decl; lead must unify those */
typedef struct { int words[9]; } S_6D6808_Copy;
typedef struct { char pad[0x14]; char f14; char pad2[0x23]; S_6D6808_Copy f38; } S_6D6808_Type2;
typedef struct { char pad[0x44]; S_6D6808_Type2 *f44; } S_6D6808_Type3;
__asm__(".extern D_L39_0024D760, 16");
extern S_6D6808_Type3 *D_L39_0024D760;

void func_L39_006D6808(S_6D6808_Copy *arg0) {
    S_6D6808_Type2 *p = D_L39_0024D760->f44;
    p->f14 = 0;
    p->f38 = *arg0;
}
