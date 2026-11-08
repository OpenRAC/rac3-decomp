/* func_L01_004AD9A0: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 6100 bytes (1525 instr), places: 34 levels, file: src/levels/shared/L01_004AD7A8.c,
   flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function; switch on state->mode (D_16C580+0x20): case 0/3 (play/skip cutscene), case 1 (path-follow
     intro), no case 2 in rac3 (rac2's case 2 -> func_002E8368 is gone); retail tests mode==1 first, then mode<2/0, then 3.
   rac2 twin: func_002E9268 (rac2-decomp src/game/002E9268.c, matched; the cutscene/movie player), opcode similarity
     0.80 (1188 equal opcodes of 1525/1440). Real twin. Same struct layouts (state, scene, moby): see the draft's types.
   Mapping (rac2 -> rac3): state D_00152C00 -> D_16C580 (same field offsets: mode +0x20, frame +0x22, skip +0x26,
     curveIndex +0x40, cameraStart/End +0x44/+0x48, progress +0x4C, speed +0x50, length +0x54, cameraBlend/Vel +0x58/+0x5C,
     fadeStart +0x6C, start/endPosition +0x90/+0xA0, rotations +0xB0/+0xC0); scene D_001B8840 -> D_L01_001E6D80
     (keys +0x68 -> +0x64, objects[] +0x1A0 same); camera D_001B5200 -> D_L01_001E29C0; screen D_001B9040 -> D_L01_001E7580;
     stream D_001A63A8 -> D_1CCFD0 (TWO mode fields now, +0x76 and +0x9E; position +0x98); curves D_001F1700 ->
     D_L01_0021F6C0; chunk length D_001A7B90 -> D_00143950 (0x50:0x60); fade D_001B15A0 -> D_L01_001DF950 ($gp+0x30A0),
     D_001B15A4 -> D_L01_001DF958 ($gp+0x30A8); controller D_00138180 (struct) -> *D_001D52FC (pointer, pressed +0x1A4).
     Callees (rac2 -> rac3): 002F5220->003E5520(mode), 002B6658->003CD058, 002E5F60->L01_004AB0E0, 0026F718->L01_004E20E8,
     002B9390->003CD350, 00294070->0039A690, 0027D330->0038A238, 0027AB40->003873C0, 0029F338->003C2880, 0029F390->003C29B0,
     002A0F48->003C7C38, 002A10E8->003C7DD8, 002A9548->L01_00447450, 0026F790->L01_004E2988, 0026F788->L01_00512A30,
     002914B8->003D0B20, 002E4AC8->003A4288, 0029FFB8->L01_0043AB98, 002F52B8->003E55B8, 002B49E0->003A0EC0,
     002B4B70->003A0F98, 002FC138->003A9050, 002B72E8->L01_0045F328, 002B7CE0->003A2750, 001261F0->0012C908,
     0029EFD0->003C24B0, 00335438->L01_003EB438, 002AA548->003C41A0, 002C9828->L01_00477998, 002A1130->L01_0043C8F8,
     002E8F80->L01_004AD808, 0027CFD0->L01_00404A10, 0027CDC8->L01_00404808, math: 00283248->0038D160 (atan2),
     00283BE0->0038DB00, 00283B98->0038DAB8, 00283180->0038D098 (cos), 00282D08->0038CDF8, 00282D30->0038CE20,
     00282E48->0038CF00, 00282E80->0038CF38, 00283410->0038D328, 00283678->0038D590, 002830C0/00283098->0038D000.
     (The 128-bit/vec helpers func_00282CC0 etc. are inline VU0 code in rac3: lqc2/vadd.xyz/sqc2, see below.)
   Identical / changed / added / removed (retail ranges, align.py rac3 vs rac2):
     identical: case 0/3 skip-table + chunk logic (004ADA84-004ADB58 etc.), object animation loop body, case 1 curve
       pre-computation (004AE828-004AEAB4: atan2 tangents, 0.22689283 scale, ramp 0.05*i), path step.
     changed: skip trigger (frame>=11 instead of 13, endFrame-25 instead of -30, both stream modes); skip-table values
       scaled (x*5+2)/6 (PAL 50->60 Hz style retime), constants 0.0324/0.0418879 (75 frames not 90)/0x6C etc.
     added: a debug-skip block (D_001D545C == 0x13 / 5 / 1 with D_00142C54, D_00142BA0, D_00142C08 bit tests
       -> sp40/var_fp/var_21 flags, endFrame = (gp[-0x2E40/-0x2E38/-0x2E30]*5+2)/6, tail dispatch to
       func_00392B20/00392C78/L01_004BA7B8/L01_004ACBC8, 004ADD7C-004ADE68 + 004ADFA0-004AE1E8); call 003E5520(mode)
       at the top of both cases; D_1A4BE0+0x16B0 store.
     removed: rac2's object-matrix pre-pass (func_002AB6D8 / point+matrix 'qcopy' lines): rac3 uses the global
       matrix D_16C650 directly; rac2's D_00214920 shadow/cleanup loops (replaced by D_L01_0023AC70[0]); case 2.
   Draft: compiles; level 01: 1392 instr vs 1525 retail (6100 B), 1495 diff rows, equal opcodes 1179 of 1525 (77%).
     This is a study draft: it keeps rac2's W/H/B/F offset macros (not allowed in a final match) and a `vu_add_xyz`
     extern standing for the five inline VU0 sequences (lqc2 vf1,..; vadd.xyz vf1,vf1,vf2; sqc2): per
     Matching-Patterns.md ("VU0 inline asm around u128_t copies", the `j`-form sqc2) these need __asm__ with vf operands,
     so a MATCH needs that technique. Constants and some exact names unchecked.
   Left for Opus: (1) replace macros by typed structs and vu_add_xyz by the j-form VU0 asm (5 sites: camera pos,
     object pos x2, hero/companion pos); (2) the sp frame is 0xB0 retail vs bigger mine: drop the sp20[16]/sp0[16]
     arrays to the retail layout (matrix at sp+0, vec at sp+0x10/0x20 as m2c shows); (3) the missing 133 instr are the
     camera-start stores after func_0038D5F0 and the debug-skip scheduling; (4) retail tests mode==1 first (put case 1
     before the 0/3 compare), as if/else chain not switch; (5) hero/companion colorData copies are `ld/sd` of
     *(u64*)(D_1A4BE0+0x25C0 ptr +0x38).
*/
#define W(p,o) (*(int *)((char *)(p)+(o)))
#define H(p,o) (*(short *)((char *)(p)+(o)))
#define UH(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define B(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad00[0xC];
    unsigned char count;
    char pad0D[0x3B];
    int slots[1];
} PlaybackClass;
typedef struct {
    char pad00[0x10];
    float position[4];
    unsigned char status;
    char pad21[3];
    PlaybackClass *classData;
    char pad28[0xA];
    short drawDistance;
    unsigned short flags;
    char pad36[2];
    unsigned long long colorData;
    unsigned char frame, nextFrame;
    char pad42[2];
    float animTime;
    char pad48[0x10];
    char *joints, *previousJoints;
    unsigned char pad60, animId, opacity, mobyState;
    char pad64[4];
    char *keys;
    char pad6C[3];
    unsigned char shadowRange;
    char pad70[8];
    unsigned int color;
    char pad7C[0x19];
    unsigned char effectOpacity;
    char pad96[2];
    int updateState;
    char pad9C[0xE];
    short classId;
    char padAC[6];
    short partFlags;
    char padB4[8];
    unsigned char effectScale;
    char padBD[3];
    float matrix[12];
    float rotation[4];
} PlaybackMoby;
typedef struct {
    PlaybackMoby *object;
    char pad04[4];
    PlaybackMoby *extra;
    char pad0C[4];
    PlaybackMoby *hero;
    PlaybackMoby *companion;
    char pad18[8];
    short mode, frame;
    short unused24, skip;
    char pad28[0x18];
    int curveIndex, cameraStart, cameraEnd;
    float progress, speed, length, cameraBlend, cameraVelocity;
    char pad60[0xC];
    int fadeStart;
    char pad70[0x20];
    float startPosition[4], endPosition[4], startRotation[4], endRotation[4];
} PlaybackState;
typedef struct {
    char pad00[0x30];
    int selected, frame, streamFrame, chunk;
    short endFrame, unused42, objectCount;
    char pad46[0x1E];
    char *keys;
    char pad68[0x138];
    PlaybackMoby *objects[1];
} PlaybackScene;
/* study draft: uses W/H/B/F offset macros from rac2's matched file (not allowed in a final match) */
extern PlaybackState D_16C580;
extern PlaybackScene D_L01_001E6D80;
extern int D_00143950;
extern int D_L01_002EDF10[];
extern float D_L01_001DF950;
extern float D_L01_001DF958;
extern int D_001D545C;
extern int D_00142C54;
extern int D_00142C08;
extern char D_00142BA0[];
extern char D_001426E0[];
extern int D_L01_001D6674, D_L01_001DFB54;
extern int D_001D9A70;
typedef struct { char pad[0x1A4]; unsigned int pressed; } PlaybackController;
extern PlaybackController *D_001D52FC;
typedef struct { char pad[0x76]; short mode0; char pad78[0x20]; short pos; short mode1; } PlaybackStream;
extern PlaybackStream D_1CCFD0;
typedef struct { char pad[0xB0]; float fieldOfView; } PlaybackScreen;
extern PlaybackScreen D_L01_001E7580;
extern char D_L01_001E29C0[];
extern char D_16C650[];
extern char D_L01_001EA7C0[];
extern char D_L01_00252880[];
extern PlaybackMoby *D_L01_0023AC70[];
extern PlaybackMoby *D_L01_001E0E68;
extern char *D_L01_001E0100;
extern int *D_L01_0021F6C0[];
extern unsigned char D_L01_001FDBDA;
extern char D_1A4BE0[];
extern unsigned char D_001439F4;
extern char D_L01_004AC618[], D_L01_004ACF48[], D_L01_004AD7A8[], D_003A7AF8[];
extern int D_001D9A70;
extern int D_001D9A78, D_001D9A80, D_001D9A7C;
extern int D_001D9A74;
extern int D_L01_001D6674;
extern void func_003E5520(short), func_003CD058(void), func_L01_004AB0E0(void), func_L01_004E20E8(void), func_003CD350(void);
extern void func_0039A690(int), func_0038A238(int), func_003A9050(int, int), func_003873C0(void);
extern void func_003C2880(void *), func_003C29B0(void *);
extern void func_L01_004B9798(int), func_L01_004BA7B8(void), func_L01_004ACBC8(int, int), func_0039EF28(void);
extern void func_00392B20(void *, int), func_00392C78(void *);
extern int func_003A0EC0(int, int, int, int, int);
extern void func_003A0F98(int, int);
extern float D_001D9A50[], D_001D9A60[];
extern void func_0038D328(void *, void *);
extern void func_0038D000(void *, void *, void *), func_0038D590(void *, void *), func_0038D5F0(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, float), func_0038CE20(void *, void *, float);
extern float func_0038D160(float, float), func_0038DB00(float, float), func_0038DAB8(float, float), func_0038D098(float);
extern float func_0038CF00(void *, void *), func_0038CF38(void *, void *, void *);
extern void func_12FF40(void *), func_130088(void *, void *, float), func_130130(void *, void *, float), func_12FFE0(void *, void *, float);
extern void func_003C7C38(void *), func_003C7DD8(void *);
extern void func_L01_00447450(void *), func_L01_004E2988(void *), func_L01_00512A30(void *, int);
extern void func_003A58C0(void *, int);
extern void func_L01_00404808(void *, void *), func_L01_00404A10(void *, void *);
extern void func_003A4288(void), func_003D0B20(void), func_L01_0043AB98(void), func_003E55B8(void);
extern void func_L01_0045F328(int), func_003A2750(int), func_003A2B68(int, int), func_003A1798(void *), func_12C908(int);
extern PlaybackMoby *func_003C24B0(int, int);
extern void func_L01_003EB438(int, void *, void *, int, int, int), func_003C41A0(void *, void *, float, float, float, float);
extern void func_L01_003EB350(int, void *), func_L01_003EB3C0(int, void *);
extern void func_L01_00477998(void *, int, void *, void *, int, float);
extern void func_L01_0043C8F8(void *, int, void *, int);
extern void func_L01_004AD808(void *, float);
extern void vu_add_xyz(void *dst, void *a, void *b); /* stands for lqc2/vadd.xyz/sqc2 inline VU0 in retail */

int func_L01_004AD9A0(void)
{
    float sp0[16], sp10[4], sp20[16];
    PlaybackState *state = &D_16C580;
    PlaybackScene *scene = &D_L01_001E6D80;

    state->frame++;
    switch (state->mode) {
    case 0:
    case 3:
        func_003E5520(state->mode);
        func_003CD058();
        func_L01_004AB0E0();
        func_L01_004E20E8();
        func_003CD350();
        {
            int skipIndex = 0, advance, chunkLength;
            scene->streamFrame++;
            scene->frame++;
            for (; D_L01_002EDF10[scene->selected * 8 + skipIndex * 2] >= 0; skipIndex++) {
                if (scene->frame == (D_L01_002EDF10[scene->selected * 8 + skipIndex * 2] * 5 + 2) / 6) {
                    advance = (D_L01_002EDF10[scene->selected * 8 + skipIndex * 2 + 1] * 5 + 2) / 6;
                    chunkLength = D_00143950 ? 0x50 : 0x60;
                    scene->frame += advance;
                    scene->streamFrame += advance;
                    if (scene->streamFrame >= chunkLength) {
                        scene->chunk = scene->frame / chunkLength;
                        func_0039A690(scene->chunk);
                        scene->streamFrame = scene->frame % chunkLength;
                    }
                    break;
                }
            }
        }
        D_L01_001DF950 -= 0.125f;
        if (D_L01_001DF950 < 0.0f) D_L01_001DF950 = 0.0f;
        {
            int limit = D_00143950 ? 0x50 : 0x60;
            int skip = state->skip;
            int endFrame;
            int flagA = 0, flagB = 0, flagC = 0, dbg, mark;
            int last;
            if ((D_001D52FC->pressed & 0x9FF) && scene->frame >= 11 && D_L01_001DF950 == 0.0f
                && scene->frame < scene->endFrame - 25) skip = 1;
            if (skip) {
                if ((unsigned short)(D_1CCFD0.mode0 - 6) >= 2) D_1CCFD0.mode0 = 5;
                if ((unsigned short)(D_1CCFD0.mode1 - 6) >= 2) D_1CCFD0.mode1 = 5;
                if (state->mode != 0) {
                    if (state->skip) state->skip = 0;
                    if (scene->frame < 5) state->fadeStart = -5;
                    else state->fadeStart = scene->frame - 1;
                } else {
                    scene->frame = scene->endFrame - 25;
                    scene->chunk = scene->frame / limit;
                    func_0039A690(scene->chunk);
                    scene->streamFrame = scene->frame % limit;
                    if (state->skip) state->skip = 0;
                    else func_0038A238(4);
                    D_L01_001DF950 = 1.0f;
                }
            }
            if (state->mode == 3) {
                int j = state->fadeStart;
                if (j == 0) j = scene->endFrame - 6;
                if (scene->frame >= j) {
                    D_L01_001DF950 = (scene->frame - j) * 0.2f;
                    if (D_L01_001DF950 > 1.0f) scene->frame = scene->endFrame;
                    if (D_L01_001DF950 > 1.0f) D_L01_001DF950 = 1.0f;
                }
            }
            dbg = D_001D545C;
            endFrame = scene->endFrame;
            if (dbg == 0x13 && state->mode == 0 && (D_00142C54 & 0x200000)) flagA = (D_00142C54 & 0x400000) == 0;
            if (dbg == 5 && state->mode == 0 && (W(D_00142BA0, 0x88) & 0x800)) flagB = (W(D_00142BA0, 0x8C) & 0x1000) == 0;
            if (dbg == 1 && state->mode == 0) flagC = (D_00142C08 & 0x400) ? dbg : 0;
            mark = D_001D9A70;
            if (flagA || (mark = D_001D9A78, flagB) || (mark = D_001D9A80, flagC)) {
                dbg = 6;
                endFrame = (mark * 5 + 2) / 6;
            }
            if (scene->frame >= endFrame) {
                int i;
                if ((unsigned short)(D_1CCFD0.mode0 - 6) >= 2) D_1CCFD0.mode0 = 5;
                if ((unsigned short)(D_1CCFD0.mode1 - 6) >= 2) D_1CCFD0.mode1 = 5;
                func_003A9050(dbg, D_00143950);
                D_L01_001E7580.fieldOfView = 0.62f;
                func_003873C0();
                for (i = 0; i < scene->objectCount; i++) {
                    PlaybackMoby *object = scene->objects[i];
                    if (object) {
                        object->classData->count--;
                        object->classData->slots[object->classData->count] = 0;
                        func_003C2880(object);
                        scene->objects[i] = 0;
                    }
                    if (state->extra) func_003C2880(state->extra);
                }
                state->object->flags &= 0xFFFE;
                if (D_L01_0023AC70[0] && D_L01_0023AC70[0]->mobyState) D_L01_0023AC70[0]->mobyState = 8;
                func_L01_004B9798(0);
                if (flagA) {
                    func_00392B20(D_L01_001EA7C0, 0xB6);
                    func_00392C78(D_L01_001EA7C0);
                    D_001D9A74 = 1;
                    func_0038A238(6);
                    B(D_001426E0, 0x82) |= 1;
                    func_0039EF28();
                    func_L01_004BA7B8();
                } else if (flagB) {
                    func_00392B20(D_L01_001EA7C0, 0x8C);
                    func_00392C78(D_L01_001EA7C0);
                    D_001D9A7C = 1;
                    func_0038A238(6);
                    func_L01_004BA7B8();
                } else if (flagC) {
                    func_L01_004ACBC8(2, 0x8C);
                } else if (state->mode == 0) {
                    if (!func_003A0EC0(3, 1, 4, 0, 0)) {
                        func_0038A238(2);
                        D_L01_001DFB54 = 1;
                    }
                } else {
                    func_003A0F98(0, 0);
                }
            } else {
                PlaybackScene *s = scene;
                char *key, *rotation;
                int last, i;
                if (s->streamFrame >= (D_00143950 ? 0x50 : 0x60)) {
                    s->chunk++;
                    func_0039A690(s->chunk);
                }
                key = s->keys + s->streamFrame * 32;
                last = B(key, 0xC);
                rotation = key + 0x10;
                D_L01_001E7580.fieldOfView = F(rotation, 0xC);
                func_003873C0();
                *(u128_t *)D_L01_001E29C0 = *(u128_t *)key;
                func_0038D000(D_L01_001E29C0, D_L01_001E29C0, D_16C650);
                vu_add_xyz(D_L01_001E29C0, D_L01_001E29C0, sp0);
                func_12FF40(sp20);
                func_130088(sp20, sp20, F(key, 0x10));
                func_130130(sp20, sp20, F(rotation, 4));
                func_12FFE0(sp20, sp20, F(rotation, 8));
                {
                    char *cam = D_L01_001E29C0 - 0x140;
                    F(cam, 0x160) = -sp20[8]; F(cam, 0x170) = -sp20[0]; F(cam, 0x180) = sp20[4];
                    F(cam, 0x164) = -sp20[9]; F(cam, 0x174) = -sp20[1]; F(cam, 0x184) = sp20[5];
                    F(cam, 0x168) = -sp20[10]; F(cam, 0x178) = -sp20[2]; F(cam, 0x188) = sp20[6];
                }
                func_0038D5F0(D_L01_001E29C0 + 0x20, D_16C650, D_L01_001E29C0 + 0x20);
                for (i = 0; i < s->objectCount; i++) {
                    PlaybackMoby *object = s->objects[i];
                    int half = s->streamFrame >> 1;
                    char *p;
                    object->frame = half;
                    object->nextFrame = half + 1;
                    func_003C29B0(object);
                    object->animTime = (float)(s->streamFrame & 1) * 0.5f;
                    if (last && (s->streamFrame & 1)) object->animTime = 1.0f;
                    p = (char *)W(object, 0x68);
                    func_0038CE20(sp0, p + object->frame * 16, 1.0f - object->animTime);
                    func_0038CE20(sp10, p + object->nextFrame * 16, object->animTime);
                    vu_add_xyz(object->position, sp0, sp10);
                    func_0038D000(object->position, object->position, D_16C650);
                    func_0038D590(object->matrix, D_16C650);
                    object->animId = 255;
                    object->flags |= 0x100;
                    func_003C7C38(object);
                    if (object->classId == 0) {
                        object->shadowRange = 0;
                        if (D_16C650[-0xB0] == 0) { if (s->frame < 0x49) object->shadowRange = 24; }
                        else if (s->frame >= 0x95) object->shadowRange = 24;
                    }
                    if (object->shadowRange) func_L01_00447450(object);
                    if (object->classId == 0x259) func_L01_004E2988(object);
                    if (object->classId == 0) func_L01_00512A30(object, 0);
                    if (object->classId == 0xD54) {
                        PlaybackMoby *p2 = 0;
                        object->mobyState = 8;
                        func_003A58C0(object, 0);
                        if (!D_L01_001E0E68 || H(D_L01_001E0E68, 0xAA) == 0xD54) func_L01_00404A10(D_003A7AF8, object);
                        func_L01_00404808(D_L01_004AC618, object);
                        if (D_L01_0023AC70[0]) p2 = D_L01_0023AC70[0];
                        if (p2) {
                            if (state->mode == 0) {
                                if (s->frame < 0x165) {
                                    int color = (int)((s->frame - 360.0f) * 1.5f);
                                    if (color > 255) color = 255;
                                    if (color < 0) color = 0;
                                    p2->color = color | (color << 8) | (color << 16);
                                    if (s->frame >= 0x120) {
                                        object->partFlags = 0;
                                        object->effectScale = (int)((s->frame - 288.0f) * 1.2f);
                                        func_L01_00404808(D_L01_004ACF48, object);
                                    }
                                    if (s->frame >= 0x144) {
                                        D_L01_001DF958 += 0.0324f;
                                        if (D_L01_001DF958 > 1.0f) D_L01_001DF958 = 1.0f;
                                    }
                                } else {
                                    p2->color = 0xA0A0A0;
                                    D_L01_001DF958 -= 0.0324f;
                                    if (D_L01_001DF958 < 0.0f) D_L01_001DF958 = 0.0f;
                                }
                            } else if (s->frame < 0x6C) {
                                int color = ((0x6C - s->frame) * 255) / 108;
                                p2->color = color | (color << 8) | (color << 16);
                                if (s->frame < 0x3A) object->effectScale = ((0x3A - s->frame) * 100) / 58;
                                object->partFlags = 0;
                                func_L01_00404808(D_L01_004ACF48, object);
                            } else {
                                int color = (int)(func_0038D098((float)((s->frame & 63) - 32) * 0.09817477f) * 80.0f) + 120;
                                p2->color = color | (color << 8) | (color << 16);
                            }
                        }
                    }
                }
                func_003A4288();
                func_003D0B20();
                func_L01_0043AB98();
                func_003E55B8();
            }
        }
        break;
    case 1:
        W(D_1A4BE0, 0x16B0) = 0;
        func_003E5520(state->mode);
        func_003CD058();
        func_L01_004AB0E0();
        func_L01_004E20E8();
        func_003CD350();
        if (state->frame == 0) {
            func_L01_0045F328(0);
            func_003A2750(0);
            func_003A2B68(0x138E, 0);
            while (D_1CCFD0.mode0 != 0 || D_1CCFD0.mode1 != 3 || D_1CCFD0.pos >= 0x1B58) {
                func_003A4288();
                func_12C908(0);
            }
            func_003A1798(&D_1CCFD0);
            state->object->opacity = 255;
            state->object->updateState = 0;
            if (state->curveIndex >= 0) {
                state->hero = func_003C24B0(0, 0x80);
                state->hero->drawDistance = 0x1FF;
                state->hero->opacity = 255;
                state->hero->updateState = 0;
                state->hero->flags |= 6;
                state->hero->colorData = *(unsigned long long *)((char *)W(D_1A4BE0, 0x25C0) + 0x38);
                if (D_L01_001FDBDA != 255 && H(D_1A4BE0, 0x2884) == 0) {
                    state->companion = func_003C24B0(10, 0x80);
                    state->companion->drawDistance = 0x1FF;
                    state->companion->opacity = 255;
                    state->companion->updateState = 0;
                    state->companion->flags |= 6;
                    state->companion->colorData = *(unsigned long long *)((char *)W(D_1A4BE0, 0x25C0) + 0x38);
                } else state->companion = 0;
            }
            func_L01_003EB438(0, D_L01_001E29C0, D_L01_001E29C0 + 0x10, 4, 0, 0);
            state->cameraBlend = 0;
            state->cameraVelocity = 0;
            if (state->curveIndex >= 0) {
                char *curve = (char *)D_L01_0021F6C0[state->curveIndex];
                float maximum = state->cameraBlend, angle, factor;
                int i;
                for (i = 1; i < W(curve, 0) - 1; i++) {
                    char *point = curve + i * 16, *previous = curve + (i - 1) * 16, *next = curve + (i + 1) * 16;
                    angle = func_0038D160(F(point, 0x10) - F(previous, 0x10), F(point, 0x14) - F(previous, 0x14));
                    factor = func_0038D160(F(next, 0x10) - F(point, 0x10), F(next, 0x14) - F(point, 0x14));
                    F(point, 0x1C) = func_0038DB00(angle, factor);
                    if (maximum < __builtin_fabsf(F(point, 0x1C))) maximum = __builtin_fabsf(F(point, 0x1C));
                }
                F(curve, 0x1C) = F(curve, 0x2C);
                {
                    char *last = curve + (W(curve, 0) - 1) * 16, *previous = curve + (W(curve, 0) - 2) * 16;
                    angle = func_0038D160(F(last, 0x10) - F(previous, 0x10), F(last, 0x14) - F(previous, 0x14));
                    factor = func_0038D160(F(curve, 0x10) - F(last, 0x10), F(curve, 0x14) - F(last, 0x14));
                    F(last, 0x1C) = func_0038DB00(factor, angle);
                }
                factor = 0.22689283f / maximum;
                for (i = 0; i < W(curve, 0); i++) F(curve + i * 16, 0x1C) *= factor;
                for (i = 0; i < 20; i++) F(curve + i * 16, 0x1C) = F(curve + i * 16, 0x1C) * 0.05f * i;
                state->length = func_0038CF00(curve + 0x10, curve + 0x20);
                state->progress = 0;
                state->speed = 0;
                *(u128_t *)state->startPosition = *(u128_t *)state->object->position;
                *(u128_t *)state->endPosition = *(u128_t *)(curve + 0x10);
                *(u128_t *)state->startRotation = *(u128_t *)state->object->rotation;
                state->endRotation[0] = F(curve, 0x1C);
                state->endRotation[1] = func_0038D160(func_0038CF38(curve + 0x20, curve + 0x10, state->object), F(curve, 0x18) - F(curve, 0x28));
                state->endRotation[2] = func_0038D160(F(curve, 0x20) - F(curve, 0x10), F(curve, 0x24) - F(curve, 0x14));
            }
        }
        if (state->cameraStart >= 0 && state->cameraEnd >= 0) {
            func_003C41A0(&state->cameraBlend, &state->cameraVelocity, 1.0f, 0.00018500001f, 0.00018500001f, 0.008333334f);
            func_0038CDF8(sp0, D_L01_001E0100 + state->cameraStart * 128 + 0x30, D_L01_001E0100 + state->cameraEnd * 128 + 0x30, state->cameraBlend);
            sp10[0] = func_0038DB00(F(D_L01_001E0100 + state->cameraEnd * 128, 0x70), F(D_L01_001E0100 + state->cameraStart * 128, 0x70)) * state->cameraBlend;
            sp10[0] = func_0038DAB8(F(D_L01_001E0100 + state->cameraStart * 128, 0x70), sp10[0]);
            sp10[1] = func_0038DB00(F(D_L01_001E0100 + state->cameraEnd * 128, 0x74), F(D_L01_001E0100 + state->cameraStart * 128, 0x74)) * state->cameraBlend;
            sp10[1] = func_0038DAB8(F(D_L01_001E0100 + state->cameraStart * 128, 0x74), sp10[1]);
            sp10[2] = func_0038DB00(F(D_L01_001E0100 + state->cameraEnd * 128, 0x78), F(D_L01_001E0100 + state->cameraStart * 128, 0x78)) * state->cameraBlend;
            sp10[2] = func_0038DAB8(F(D_L01_001E0100 + state->cameraStart * 128, 0x78), sp10[2]);
            func_L01_003EB350(0, sp0);
            func_L01_003EB3C0(0, sp10);
        }
        if (state->curveIndex >= 0) {
            PlaybackMoby *o = state->object;
            if (state->frame < 120) {
                float blend = (1.0f - func_0038D098((float)state->frame * 0.0418879f)) * 0.5f;
                if (state->frame >= 75) blend = 1.0f;
                func_0038CDF8(o->position, state->startPosition, state->endPosition, blend);
                o->rotation[0] = state->endRotation[0] * blend;
                o->rotation[1] = func_0038DAB8(state->startRotation[1], func_0038DB00(state->endRotation[1], state->startRotation[1]) * blend);
                o->rotation[2] = func_0038DAB8(state->startRotation[2], func_0038DB00(state->endRotation[2], state->startRotation[2]) * blend);
                func_0038D328(sp0, o->rotation);
                func_0038D590(o->matrix, sp0);
                func_003C7DD8(o);
                if (D_L01_001DF950 > 0.0f) {
                    D_L01_001DF950 -= 0.125f;
                    if (D_L01_001DF950 < 0.0f) D_L01_001DF950 = 0.0f;
                }
                o->effectOpacity = (unsigned short)state->frame >> 2;
                if (blend < 1.0f) func_L01_004AD808(o, -0.0625f);
            } else {
                char *curve = (char *)D_L01_0021F6C0[state->curveIndex];
                float step;
                state->speed += 0.8f;
                if (state->speed > 100.0f) state->speed = 100.0f;
                if ((D_001D52FC->pressed & 0x50) && D_L01_001DF950 < 0.1f) D_L01_001DF950 = 0.1f;
                step = state->speed * 0.020000001f / state->length;
                if ((float)W(curve, 0) - step * 12.0f < state->progress && D_L01_001DF950 < 0.1f) D_L01_001DF950 = 0.1f;
                if (D_L01_001DF950 > 0.0f) {
                    D_L01_001DF950 += 0.1f;
                    if (D_L01_001DF950 > 1.0f) D_L01_001DF950 = 1.0f;
                }
                if (o->effectOpacity < 200) o->effectOpacity += 6;
                state->progress += step;
                if (state->progress > (float)(W(curve, 0) - 1) || D_L01_001DF950 >= 1.0f) {
                    W(D_1A4BE0, 0x16B0) = D_001439F4;
                    func_0038A238(2);
                    D_L01_001D6674 = 1;
                } else {
                    func_L01_00477998(curve, 1, o->position, o->rotation, 0, state->progress);
                    o->rotation[0] = o->rotation[3];
                    func_0038D328(sp0, o->rotation);
                    func_0038D590(o->matrix, sp0);
                    func_003C7DD8(o);
                }
            }
            *(u128_t *)state->hero->rotation = *(u128_t *)o->rotation;
            func_0038D000(state->hero->position, D_001D9A50, o->matrix);
            vu_add_xyz(state->hero->position, state->hero->position, o->position);
            func_003C7C38(state->hero);
            {
                char *cd = (char *)state->hero->classData;
                char *bones = (char *)W(cd, 0x48);
                func_L01_0043C8F8(bones + B(bones, 0x10) * 4 + 0x1C + B(bones, 0x13) * 4, W(bones, 0x1C), D_L01_00252880, B(cd, 8));
                state->hero->joints = D_L01_00252880;
                state->hero->previousJoints = D_L01_00252880;
            }
            if (state->companion) {
                *(u128_t *)state->companion->rotation = *(u128_t *)o->rotation;
                func_0038D000(state->companion->position, D_001D9A60, o->matrix);
                vu_add_xyz(state->companion->position, state->companion->position, o->position);
                func_003C7C38(state->companion);
            }
        } else {
            D_L01_001DF950 = 1.0f;
            W(D_1A4BE0, 0x16B0) = D_001439F4;
            D_L01_001D6674 = 1;
        }
        func_003A58C0(state->object, 0);
        func_L01_00404A10(D_L01_004AD7A8, state->object);
        func_003A4288();
        func_003D0B20();
        func_L01_0043AB98();
        func_003E55B8();
        break;
    }
    return 0;
}
