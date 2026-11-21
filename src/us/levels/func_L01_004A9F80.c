#include "common.h"

/* NTSC-U counterpart of func_L01_004AD9A0 (src/levels/shared/L01_004AD7A8.c) */
#include "vu0.h"
extern void func_003888C8(void *, void *, void *);

/* localdecomp:start func_L01_004A9F80 */
#include "vu0.h"

typedef struct {
    u8 pad00[0xC];
    u8 count;
    u8 pad0D[0x3B];
    s32 slots[1];
} PlaybackClass;
typedef struct {
    u8 pad00[0x10];
    vu0_v4 position;
    u8 status;
    u8 pad21[3];
    PlaybackClass *classData;
    u8 pad28[0xA];
    s16 drawDistance;
    u16 flags;
    u8 pad36[2];
    unsigned long colorData;
    u8 frame, nextFrame;
    u8 pad42[2];
    f32 animTime;
    u8 pad48[0x10];
    u8 *joints, *previousJoints;
    u8 pad60, animId, opacity, mobyState;
    u8 pad64[4];
    u8 *keys;
    u8 pad6C[3];
    u8 shadowRange;
    u8 pad70[8];
    u32 color;
    u8 pad7C[0x19];
    u8 effectOpacity;
    u8 pad96[2];
    s32 updateState;
    u8 pad9C[0xE];
    s16 classId;
    u8 padAC[6];
    s16 partFlags;
    u8 padB4[8];
    u8 effectScale;
    u8 padBD[3];
    f32 matrix[12];
    vu0_v4 rotation;
} PlaybackMoby;
typedef struct {
    PlaybackMoby *object;
    u8 pad04[4];
    PlaybackMoby *extra;
    u8 pad0C[4];
    PlaybackMoby *hero;
    PlaybackMoby *companion;
    u8 pad18[8];
    s16 mode, frame;
    s16 unused24, skip;
    u8 pad28[0x18];
    s32 curveIndex, cameraStart, cameraEnd;
    f32 progress, speed, length, cameraBlend, cameraVelocity;
    u8 pad60[0xC];
    s32 fadeStart;
    u8 pad70[0x20];
    vu0_v4 startPosition, endPosition, startRotation, endRotation;
    vu0_v4 matrix[4];
} PlaybackState;
typedef struct {
    u8 pad00[0x30];
    s32 selected, frame, streamFrame, chunk;
    s16 endFrame, unused42, objectCount;
    u8 pad46[0x1E];
    u8 *keys;
    u8 pad68[0x138];
    PlaybackMoby *objects[1];
} PlaybackScene;
typedef struct { s32 at, advance; } PlaybackSkip;
typedef struct { u8 pad[0x1A4]; u32 pressed; } PlaybackPad;
typedef struct { u8 pad[0x76]; s16 mode0; u8 pad78[0x20]; s16 position; u8 pad9A[4]; s16 mode1; } PlaybackStream;
typedef struct { u8 pad[0xB0]; f32 fieldOfView; } PlaybackScreen;
typedef struct {
    u8 pad00[0x140];
    vu0_v4 position, rotation;
    f32 forward[4], right[4], up[4];
} PlaybackCamera;
typedef struct { f32 x, y, z, rot; } PlaybackPoint;
typedef struct { s32 count; u8 pad04[0xC]; PlaybackPoint points[1]; } PlaybackCurve;
typedef struct { u8 pad00[0x10]; u8 n10; u8 pad11[2]; u8 n13; u8 pad14[8]; s32 a1C[1]; } PlaybackBones;
typedef struct { u8 pad[0x70]; f32 angles[4]; } PlaybackCamRecord;

extern PlaybackState D_0016C580;
extern PlaybackScene D_L01_001E6E00;
extern PlaybackSkip D_L01_002EDF60[][4];
extern s32 D_00143950[];
extern f32 D_L01_001DF9D0;
extern f32 D_L01_001DF9D8;
extern PlaybackPad *D_001D52FC;
extern PlaybackStream D_001CCFD0;
extern s32 D_001D545C;
extern s32 D_00142C54[];
extern s32 D_00142C08[];
extern s32 D_00142BA0[];
extern u8 D_001426E0[];
extern s32 D_L01_001D9AA0, D_L01_001D9AA4, D_L01_001D9AA8, D_L01_001D9AAC, D_L01_001D9AB0;
extern s32 D_L01_001DFBD4;
extern s32 D_L01_001D6674_004A9F80;
extern s16 D_L01_001D6706_004A9F80;
extern PlaybackScreen D_L01_001E7600;
extern PlaybackCamera D_L01_001E2900;
extern PlaybackMoby *D_L01_0023ACF0[];
extern PlaybackMoby *D_L01_001E0EE8;
extern u8 D_L01_001EA840[];
extern u8 *D_L01_001E0180;
extern PlaybackCurve *D_L01_0021F740[];
extern u8 D_L01_001FDC5A[];
extern u8 D_001A4BE0[];
extern u8 D_001439F4[];
extern f32 D_L01_001D9A80_004A9F80[2] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9A80_004A9F80, 8");
extern f32 D_L01_001D9A90[2] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9A90, 8");
extern u8 D_L01_00252900[];

extern void func_003DFFD0();
extern void func_003C7AE8(void);
extern void func_L01_004A76F0(void);
extern void func_L01_004DE348(void);
extern void func_003C7DE0(void);
extern void func_003958A0(s32);
extern void func_00385B60(s32);
extern void func_003A3B00(void);
extern void func_003830E8(void);
extern void func_003BD360(void *);
extern void func_L01_004B5C00(s32);
extern void func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_00399F90(void);
extern void func_L01_004B6C20(void);
extern void func_L01_004A91D8(s32);
extern s32 func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_0039BF98(s32, s32);
extern void func_003888C8(void *, void *, void *);
extern void func_0012FF40(void *);
extern void func_00130088(void *, void *, f32);
extern void func_00130130(void *, void *, f32);
extern void func_0012FFE0(void *, void *, f32);
extern void func_00388EB8(void *, void *, void *);
extern void func_003BD490(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388E58(void *, void *);
extern void func_003C26C8(void *);
extern void func_L01_00444318_004A9F80(void *);
extern void func_L01_004DEBC0(void *);
extern void func_L01_0050EA58(void *, s32);
extern void func_003A04A0(void *, s32);
extern void func_003A26D0();
extern void func_L01_004A8C28();
extern void func_L01_004A9558();
extern void func_L01_004026A0_004A9F80(void *, void *);
extern void func_L01_00402498(void *, void *);
extern f32 func_00388960(f32);
extern void func_0039EE68(void);
extern void func_003CB5B0(void);
extern void func_L01_00437AB8(void);
extern void func_003E0068(void);
extern void func_L01_0045BF98(s32);
extern void func_0039D6C8(s32);
extern void func_0039DAE0(s32, s32);
extern void func_0012C908(s32);
extern void func_0039C710(void);
extern PlaybackMoby *func_003BCFB0(s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_003BEC60(void *, f32, f32, f32, f32, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L01_003E94A0(s32, void *);
extern void func_L01_003E9510(s32, void *);
extern void func_00388BF0(void *, void *);
extern void func_003C2868(void *);
extern void func_L01_004A9DE8(void *, f32);
extern void func_L01_00474140(void *, s32, void *, void *, s32, f32);
extern void func_L01_004397F8(void *, s32, void *, s32);
extern void func_00380AB0(void);
extern void func_L01_004A9D88(s32);

#define state (&D_0016C580)
#define W(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
#define scene (&D_L01_001E6E00)
#define REC(n) ((PlaybackCamRecord *)(D_L01_001E0180 + (n) * 128))

s32 func_L01_004A9F80(void)
{
    f32 temp[16] __attribute__((aligned(16)));

    state->frame++;
    switch (state->mode) {
    case 0:
    case 3:
        func_003DFFD0();
        func_003C7AE8();
        func_L01_004A76F0();
        func_L01_004DE348();
        func_003C7DE0();
        scene->streamFrame++;
        scene->frame++;
        {
            s32 skipIndex, advance, chunkLength;
            for (skipIndex = 0; D_L01_002EDF60[scene->selected][skipIndex].at >= 0; skipIndex++) {
                if (scene->frame == D_L01_002EDF60[scene->selected][skipIndex].at) {
                    advance = D_L01_002EDF60[scene->selected][skipIndex].advance;
                    chunkLength = D_00143950[0] ? 80 : 96;
                    scene->frame += advance;
                    scene->streamFrame += advance;
                    if (scene->streamFrame >= chunkLength) {
                        scene->chunk = scene->frame / chunkLength;
                        func_003958A0(scene->chunk);
                        scene->streamFrame = scene->frame % chunkLength;
                    }
                    break;
                }
            }
        }
        D_L01_001DF9D0 -= 0.125f;
        if (D_L01_001DF9D0 < 0.0f) D_L01_001DF9D0 = 0.0f;
        {
            s32 limit, skip;
            limit = D_00143950[0] ? 80 : 96;
            skip = state->skip;
            if ((D_001D52FC->pressed & 0x9FF) && scene->frame >= 13 && D_L01_001DF9D0 == 0.0f
                && scene->frame < scene->endFrame - 30) skip = 1;
            if (skip) {
                if ((u16)((u16)D_001CCFD0.mode0 - 6) >= 2) D_001CCFD0.mode0 = 5;
                if ((u16)((u16)D_001CCFD0.mode1 - 6) >= 2) D_001CCFD0.mode1 = 5;
                if (state->mode == 0) {
                    scene->frame = scene->endFrame - 30;
                    scene->chunk = scene->frame / limit;
                    func_003958A0(scene->chunk);
                    scene->streamFrame = scene->frame % limit;
                    if (state->skip) state->skip = 0;
                    else func_00385B60(4);
                    D_L01_001DF9D0 = 1.0f;
                } else {
                    if (state->skip) state->skip = 0;
                    if (scene->frame < 5) state->fadeStart = -5;
                    else state->fadeStart = scene->frame - 1;
                }
            }
        }
        if (state->mode == 3) {
            s32 j;
            j = state->fadeStart;
            if (j == 0) j = scene->endFrame - 6;
            if (scene->frame >= j) {
                D_L01_001DF9D0 = (scene->frame - j) * 0.2f;
                if (D_L01_001DF9D0 > 1.0f) scene->frame = scene->endFrame;
                if (D_L01_001DF9D0 > 1.0f) D_L01_001DF9D0 = 1.0f;
            }
        }
        {
            s32 endFrame, flagA, flagB, flagC;
            endFrame = scene->endFrame;
            flagA = 0;
            if (D_001D545C == 0x13 && state->mode == 0 && (D_00142C54[0] & 0x200000))
                if (!(D_00142C54[0] & 0x400000)) flagA = 1;
            flagB = 0;
            if (D_001D545C == 5 && state->mode == 0 && (D_00142BA0[0x88 / 4] & 0x800))
                if (!(D_00142BA0[0x8C / 4] & 0x1000)) flagB = 1;
            flagC = 0;
            if (D_001D545C == 1 && state->mode == 0 && (D_00142C08[0] & 0x400))
                flagC = D_001D545C;
            if (flagA) endFrame = D_L01_001D9AA0;
            else if (flagB) endFrame = D_L01_001D9AA8;
            else if (flagC) endFrame = D_L01_001D9AB0;
            if (scene->frame >= endFrame) {
                s32 i;
                if ((u16)((u16)D_001CCFD0.mode0 - 6) >= 2) D_001CCFD0.mode0 = 5;
                if ((u16)((u16)D_001CCFD0.mode1 - 6) >= 2) D_001CCFD0.mode1 = 5;
                func_003A3B00();
                D_L01_001E7600.fieldOfView = 0.62f;
                func_003830E8();
                for (i = 0; i < scene->objectCount; i++) {
                    PlaybackMoby *object = scene->objects[i];
                    if (object) {
                        object->classData->count--;
                        object->classData->slots[object->classData->count] = 0;
                        func_003BD360(object);
                        scene->objects[i] = 0;
                    }
                    if (state->extra) func_003BD360(state->extra);
                }
                state->object->flags &= 0xFFFE;
                {
                    s32 k;
                    for (k = 0; D_L01_0023ACF0[k]; k++)
                        if (D_L01_0023ACF0[k]->mobyState) D_L01_0023ACF0[k]->mobyState = 8;
                }
                func_L01_004B5C00(0);
                if (flagA) {
                    func_0038E2E8(D_L01_001EA840, 0xB6);
                    func_0038E440(D_L01_001EA840);
                    D_L01_001D9AA4 = 1;
                    func_00385B60(6);
                    D_001426E0[0x82] |= 1;
                    func_00399F90();
                    func_L01_004B6C20();
                } else if (flagB) {
                    func_0038E2E8(D_L01_001EA840, 0x8C);
                    func_0038E440(D_L01_001EA840);
                    D_L01_001D9AAC = 1;
                    func_00385B60(6);
                    func_L01_004B6C20();
                } else if (flagC) {
                    func_L01_004A91D8(2);
                } else if (state->mode == 0) {
                    if (!func_0039BEC0(3, 1, 4, 0, 0)) {
                        func_00385B60(2);
                        D_L01_001DFBD4 = 1;
                    }
                } else {
                    func_0039BF98(0, 0);
                }
            } else {
                u8 *key, *rotation;
                s32 last, i;
                {
                    s32 chunkLength = D_00143950[0] ? 80 : 96;
                    if (scene->streamFrame >= chunkLength) {
                        scene->chunk++;
                        func_003958A0(scene->chunk);
                    }
                }
                key = scene->keys + scene->streamFrame * 32;
                last = key[0xC];
                rotation = key + 0x10;
                D_L01_001E7600.fieldOfView = ((f32 *)rotation)[3];
                func_003830E8();
                *(vu0_q *)&D_L01_001E2900.position = *(vu0_q *)key;
                func_003888C8(&D_L01_001E2900.position, &D_L01_001E2900.position, state->matrix);
                vec_add_ba(&D_L01_001E2900.position, &D_L01_001E2900.position, &state->matrix[3]);
                func_0012FF40(temp);
                func_00130088(temp, temp, *(f32 *)(key + 0x10));
                func_00130130(temp, temp, ((f32 *)rotation)[1]);
                func_0012FFE0(temp, temp, ((f32 *)rotation)[2]);
                D_L01_001E2900.forward[0] = -temp[8]; D_L01_001E2900.right[0] = -temp[0]; D_L01_001E2900.up[0] = temp[4];
                D_L01_001E2900.forward[1] = -temp[9]; D_L01_001E2900.right[1] = -temp[1]; D_L01_001E2900.up[1] = temp[5];
                D_L01_001E2900.forward[2] = -temp[10]; D_L01_001E2900.right[2] = -temp[2]; D_L01_001E2900.up[2] = temp[6];
                func_00388EB8(D_L01_001E2900.forward, state->matrix, D_L01_001E2900.forward);
                for (i = 0; i < scene->objectCount; i++) {
                    PlaybackMoby *object = scene->objects[i];
                    u8 *keys;
                    s32 half = scene->streamFrame >> 1;
                    object->frame = half;
                    object->nextFrame = half + 1;
                    func_003BD490(object);
                    object->animTime = (f32)(scene->streamFrame & 1) * 0.5f;
                    if (last && (scene->streamFrame & 1)) object->animTime = 1.0f;
                    keys = object->keys;
                    func_003886E8(temp, keys + object->frame * 16, 1.0f - object->animTime);
                    func_003886E8(temp + 4, keys + object->nextFrame * 16, object->animTime);
                    vec_add_ba(&object->position, temp, temp + 4);
                    func_003888C8(&object->position, &object->position, state->matrix);
                    vec_add_ab(&object->position, &object->position, &state->matrix[3]);
                    func_00388E58(object->matrix, state->matrix);
                    object->animId = 255;
                    object->flags |= 0x100;
                    func_003C26C8(object);
                    if (object->classId == 0) {
                        object->shadowRange = 0;
                        if (state->mode == 0) {
                            if (scene->frame < 0x57) object->shadowRange = 24;
                        } else {
                            if (scene->frame >= 0xB3) object->shadowRange = 24;
                        }
                    }
                    if (object->shadowRange) func_L01_00444318_004A9F80(object);
                    if (object->classId == 0x259) func_L01_004DEBC0(object);
                    if (object->classId == 0) func_L01_0050EA58(object, 0);
                    if (object->classId == 0xD54) {
                        PlaybackMoby *cast_moby;
                        s32 cast;
                        object->mobyState = 8;
                        func_003A04A0(object, 0);
                        if (!D_L01_001E0EE8 || D_L01_001E0EE8->classId == 0xD54)
                            func_L01_004026A0_004A9F80(func_003A26D0, object);
                        func_L01_00402498(func_L01_004A8C28, object);
                        cast_moby = 0;
                        for (cast = 0; D_L01_0023ACF0[cast]; cast++) {
                            if (D_L01_0023ACF0[cast]->classId == D_L01_001D6706_004A9F80) {
                                cast_moby = D_L01_0023ACF0[cast];
                                break;
                            }
                        }
                        if (cast_moby) {
                            if (state->mode == 0) {
                                if (scene->frame < 0x1AC) {
                                    s32 color = (s32)((scene->frame - 284.0f) * 1.5f);
                                    if (color > 255) color = 255;
                                    if (color < 0) color = 0;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                    if (scene->frame >= 0x159) {
                                        object->effectScale = (s32)((scene->frame - 344.0f) * 1.2f);
                                        object->partFlags = 0;
                                        func_L01_00402498(func_L01_004A9558, object);
                                    }
                                    if (scene->frame >= 0x185) {
                                        D_L01_001DF9D8 += 0.027f;
                                        if (D_L01_001DF9D8 > 1.0f) D_L01_001DF9D8 = 1.0f;
                                    }
                                } else {
                                    *(u32 *)((u8 *)cast_moby + 0x78) = 0xA0A0A0;
                                    D_L01_001DF9D8 -= 0.027f;
                                    if (D_L01_001DF9D8 < 0.0f) D_L01_001DF9D8 = 0.0f;
                                }
                            } else {
                                if (scene->frame < 0x82) {
                                    s32 color = ((0x82 - scene->frame) * 255) / 0x82;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                    if (scene->frame < 0x46) object->effectScale = ((0x46 - scene->frame) * 100) / 0x46;
                                    object->partFlags = 0;
                                    func_L01_00402498(func_L01_004A9558, object);
                                } else {
                                    s32 color = (s32)(func_00388960((f32)((scene->frame & 63) - 32) * 0.09817477f) * 80.0f) + 120;
                                    cast_moby->color = color | (color << 8) | (color << 16);
                                }
                            }
                        }
                    }
                }
                func_0039EE68();
                func_003CB5B0();
                func_L01_00437AB8();
                func_003E0068();
            }
        }
        break;
    case 1:
        { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = 0; }
        func_003DFFD0();
        func_003C7AE8();
        func_L01_004A76F0();
        func_L01_004DE348();
        func_003C7DE0();
        if (state->frame == 0) {
            func_L01_0045BF98(0);
            func_0039D6C8(0);
            func_0039DAE0(0x138E, 0);
            while (D_001CCFD0.mode0 != 0 || D_001CCFD0.mode1 != 3 || D_001CCFD0.position >= 7000) {
                func_0039EE68();
                func_0012C908(0);
            }
            func_0039C710();
            state->object->opacity = 255;
            state->object->updateState = 0;
            if (state->curveIndex >= 0) {
                u8 *global;
                state->hero = func_003BCFB0(0, 0x80);
                global = D_001A4BE0;
                state->hero->drawDistance = 0x1FF;
                state->hero->opacity = 255;
                state->hero->updateState = 0;
                state->hero->flags |= 6;
                state->hero->colorData = *(unsigned long *)(*(u8 **)(global + 0x25C0) + 0x38);
                if (D_L01_001FDC5A[0] != 255 && *(s16 *)(global + 0x2884) == 0) {
                    state->companion = func_003BCFB0(10, 0x80);
                    state->companion->drawDistance = 0x1FF;
                    state->companion->opacity = 255;
                    state->companion->updateState = 0;
                    state->companion->flags |= 6;
                    state->companion->colorData = *(unsigned long *)(*(u8 **)(global + 0x25C0) + 0x38);
                } else state->companion = 0;
            }
            func_L01_003E9588(0, &D_L01_001E2900.position, &D_L01_001E2900.rotation, 4, 0, 0);
            state->cameraBlend = 0;
            state->cameraVelocity = 0;
            if (state->curveIndex >= 0) {
                u8 *curve;
                f32 maximum, angle, factor;
                curve = (u8 *)D_L01_0021F740[state->curveIndex];
                maximum = state->cameraBlend;
                {
                    s32 pathIndex;
                    for (pathIndex = 1; pathIndex < W(curve, 0) - 1; pathIndex++) {
                        u8 *point = curve + pathIndex * 16;
                        {
                            u8 *previous = curve + (pathIndex - 1) * 16;
                            angle = func_00388A28(F(point, 0x10) - F(previous, 0x10), F(point, 0x14) - F(previous, 0x14));
                        }
                        {
                            u8 *next = curve + (pathIndex + 1) * 16;
                            factor = func_00388A28(F(next, 0x10) - F(point, 0x10), F(next, 0x14) - F(point, 0x14));
                        }
                        F(point, 0x1C) = func_003893C8(angle, factor);
                        if (maximum < fabs_asm(F(point, 0x1C))) maximum = fabs_asm(F(point, 0x1C));
                    }
                }
                F(curve, 0x1C) = F(curve, 0x2C);
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    u8 *previous = curve + (W(curve, 0) - 2) * 16;
                    angle = func_00388A28(F(last, 0x10) - F(previous, 0x10), F(last, 0x14) - F(previous, 0x14));
                }
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    factor = func_00388A28(F(curve, 0x10) - F(last, 0x10), F(curve, 0x14) - F(last, 0x14));
                }
                angle = func_003893C8(factor, angle);
                factor = 0.2268928f / maximum;
                {
                    u8 *last = curve + (W(curve, 0) - 1) * 16;
                    F(last, 0x1C) = angle;
                }
                {
                    s32 scaleIndex;
                    for (scaleIndex = 0; scaleIndex < W(curve, 0); scaleIndex++) F(curve + scaleIndex * 16, 0x1C) *= factor;
                }
                {
                    s32 rampIndex;
                    for (rampIndex = 0; rampIndex < 20; rampIndex++)
                        F(curve + rampIndex * 16, 0x1C) = F(curve + rampIndex * 16, 0x1C) * (rampIndex * 0.05f);
                }
                state->length = func_003887C8(curve + 0x10, curve + 0x20);
                state->progress = 0;
                state->speed = 0;
                *(vu0_q *)&state->startPosition = *(vu0_q *)&state->object->position;
                *(vu0_q *)&state->endPosition = *(vu0_q *)(curve + 0x10);
                *(vu0_q *)&state->startRotation = *(vu0_q *)&state->object->rotation;
                state->endRotation.x = F(curve, 0x1C);
                angle = func_00388800(curve + 0x20, curve + 0x10);
                state->endRotation.y = func_00388A28(angle, F(curve, 0x18) - F(curve, 0x28));
                state->endRotation.z = func_00388A28(F(curve, 0x20) - F(curve, 0x10), F(curve, 0x24) - F(curve, 0x14));
            }
        }
        if (state->cameraStart >= 0 && state->cameraEnd >= 0) {
            f32 angle;
            func_003BEC60(&state->cameraBlend, 1.0f, 0.00018500001f, 0.00018500001f, 0.008333334f, &state->cameraVelocity);
            func_003886C0(temp, D_L01_001E0180 + state->cameraStart * 128 + 0x30, D_L01_001E0180 + state->cameraEnd * 128 + 0x30, state->cameraBlend);
            angle = func_003893C8(REC(state->cameraEnd)->angles[0], REC(state->cameraStart)->angles[0]);
            temp[4] = angle * state->cameraBlend;
            temp[4] = func_00389380(REC(state->cameraStart)->angles[0], temp[4]);
            angle = func_003893C8(REC(state->cameraEnd)->angles[1], REC(state->cameraStart)->angles[1]);
            temp[5] = angle * state->cameraBlend;
            temp[5] = func_00389380(REC(state->cameraStart)->angles[1], temp[5]);
            angle = func_003893C8(REC(state->cameraEnd)->angles[2], REC(state->cameraStart)->angles[2]);
            temp[6] = angle * state->cameraBlend;
            temp[6] = func_00389380(REC(state->cameraStart)->angles[2], temp[6]);
            func_L01_003E94A0(0, temp);
            func_L01_003E9510(0, temp + 4);
        }
        if (state->curveIndex >= 0) {
            u8 *classData;
            PlaybackBones *bones;
            s32 *table;
            if (state->frame < 120) {
                f32 blend;
                blend = (1.0f - func_00388960(state->frame * 0.034906585f)) * 0.5f;
                if (state->frame >= 90) blend = 1.0f;
                func_003886C0(&state->object->position, &state->startPosition, &state->endPosition, blend);
                state->object->rotation.x = state->endRotation.x * blend;
                state->object->rotation.y = func_00389380(state->startRotation.y, func_003893C8(state->endRotation.y, state->startRotation.y) * blend);
                state->object->rotation.z = func_00389380(state->startRotation.z, func_003893C8(state->endRotation.z, state->startRotation.z) * blend);
                func_00388BF0(temp, &state->object->rotation);
                func_00388E58(state->object->matrix, temp);
                func_003C2868(state->object);
                if (D_L01_001DF9D0 > 0.0f) {
                    D_L01_001DF9D0 -= 0.125f;
                    if (D_L01_001DF9D0 < 0.0f) D_L01_001DF9D0 = 0.0f;
                }
                state->object->effectOpacity = (u16)state->frame >> 2;
                if (blend < 1.0f) func_L01_004A9DE8(state->object, -0.0625f);
            } else {
                PlaybackCurve *curve;
                f32 step;
                curve = D_L01_0021F740[state->curveIndex];
                state->speed += 0.8f;
                if (state->speed > 100.0f) state->speed = 100.0f;
                if ((D_001D52FC->pressed & 0x50) && D_L01_001DF9D0 < 0.1f) D_L01_001DF9D0 = 0.1f;
                step = state->speed * 0.016666668f / state->length;
                if ((f32)curve->count - step * 12.0f < state->progress && D_L01_001DF9D0 < 0.1f) D_L01_001DF9D0 = 0.1f;
                if (D_L01_001DF9D0 > 0.0f) {
                    D_L01_001DF9D0 += 0.1f;
                    if (D_L01_001DF9D0 > 1.0f) D_L01_001DF9D0 = 1.0f;
                }
                if (state->object->effectOpacity < 200) state->object->effectOpacity += 6;
                state->progress += step;
                if (state->progress > (f32)(curve->count - 1) || D_L01_001DF9D0 >= 1.0f) {
                    { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = D_001439F4[0]; }
                    func_00385B60(2);
                    D_L01_001D6674_004A9F80 = 1;
                } else {
                    func_L01_00474140(curve, 1, &state->object->position, &state->object->rotation, 0, state->progress);
                    state->object->rotation.x = state->object->rotation.w;
                    func_00388BF0(temp, &state->object->rotation);
                    func_00388E58(state->object->matrix, temp);
                    func_003C2868(state->object);
                }
            }
            *(vu0_q *)&state->hero->rotation = *(vu0_q *)&state->object->rotation;
            func_003888C8(&state->hero->position, D_L01_001D9A80_004A9F80, state->object->matrix);
            vec_add_ab(&state->hero->position, &state->hero->position, &state->object->position);
            func_003C26C8(state->hero);
            classData = (u8 *)state->hero->classData;
            bones = *(PlaybackBones **)(classData + 0x48);
            table = &bones->a1C[bones->n10];
            func_L01_004397F8(table + bones->n13, bones->a1C[0], D_L01_00252900, classData[8]);
            state->hero->joints = D_L01_00252900;
            state->hero->previousJoints = D_L01_00252900;
            if (state->companion) {
                *(vu0_q *)&state->companion->rotation = *(vu0_q *)&state->object->rotation;
                func_003888C8(&state->companion->position, D_L01_001D9A90, state->object->matrix);
                vec_add_ab(&state->companion->position, &state->companion->position, &state->object->position);
                func_003C26C8(state->companion);
            }
        } else {
            D_L01_001DF9D0 = 1.0f;
            { u8 *h = D_001A4BE0; *(s32 *)(h + 0x16B0) = D_001439F4[0]; }
            D_L01_001D6674_004A9F80 = 1;
        }
        func_003A04A0(state->object, 0);
        func_L01_004026A0_004A9F80(func_L01_004A9D88, state->object);
        func_00380AB0();
        func_0039EE68();
        func_003CB5B0();
        func_L01_00437AB8();
        func_003E0068();
        break;
    }
    return 0;
}
#undef state
#undef scene
#undef REC
#undef W
#undef F
/* localdecomp:end func_L01_004A9F80 */
