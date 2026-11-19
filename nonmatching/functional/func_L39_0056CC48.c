/* functional: high. Plain C for retail's vsub/vadd.xyz and fabs; behaviour identical, bytes differ. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_CC48;
typedef struct { u8 pad[0x70]; u8 *data; u8 pad74[0x20]; int index; } M_CC48;
extern u8 D_L39_0024DE80[];
extern s32 D_L39_002412DC;
extern s32 D_L39_0024B868[];
extern u8 D_L39_0025F760[];
extern void func_0038CF68(void *dst, void *src, float f);
extern float func_0038CE68(void *a, void *b);
extern void func_0038CE20(void *dst, void *src, float f);
extern int func_L01_003E4168(void *pos);
extern int func_L01_003FB640(void *pos, int a, int b, float speed);
extern int func_L01_003E7F48(M_CC48 *m, int i, void *pos, float speed);
extern int func_L01_003E7B80(M_CC48 *m, void *pos, int i, float total, float speed);

int func_L39_0056CC48(M_CC48 *m) {
    V_CC48 origin, pos, step, hit, hitpos, temp;
    u8 *base = m->data + 0x60;
    u8 *motion = m->data + 0x180;
    u8 *state = m->data + 0x210;
    u8 *hero = D_L39_0024DE80 + m->index * 0x460;
    u8 *sub = hero + 0x150;
    int result = 0, changed = 0, i;
    float speed = 0.35f, total = 0.0f;
    origin = *(V_CC48 *)motion;
    pos = *(V_CC48 *)(m->data + 0xB0);
    func_0038CF68(&step, &origin, 1.0f);
    if (D_L39_002412DC == 0x30 || D_L39_002412DC == 0x1C) {
        if (!(D_L39_0024B868[m->index] & 0x20)) {
            changed = 1;
            D_L39_0024B868[m->index] |= 0x20;
        }
    }
    for (i = 0; i < (int)(*(float *)(state + 0x40) - 1.0f); i++) {
        if (i > 0 && !func_L01_003E4168(&pos)
            && func_L01_003FB640(&pos, D_L39_0024B868[m->index], *(int *)(sub + 0xF0), speed)
            && !func_L01_003E7F48(m, i, &pos, speed)) {
            hit = *(V_CC48 *)D_L39_0025F760;
            hitpos = pos;
            if (func_L01_003E7B80(m, &pos, i, total, speed)) {
                result = 1;
                {
                    float d = *(float *)(*(u8 **)(sub + 0x134) + 0x100);
                    if (d < 0.0f) d = -d;
                    if (d > 0.05f) {
                        temp.x = hit.x - hitpos.x; temp.y = hit.y - hitpos.y; temp.z = hit.z - hitpos.z;
                        func_0038CF68(&temp, &temp, 1.0f);
                        {
                            float dp = func_0038CE68(hero + 0x90, &temp);
                            if (dp < 0.0f) dp = -dp;
                            if (dp < 0.75f) {
                                *(u16 *)(state + 0x34) = 0x719;
                                *(float *)(state + 0x30) += 0.09f;
                                if (*(float *)(motion + 0x2C) - *(float *)(state + 0x30) < 0.2f)
                                    *(float *)(state + 0x30) = *(float *)(motion + 0x2C) - 0.2f;
                            }
                        }
                    }
                }
                {
                    V_CC48 *o = (V_CC48 *)(base + 0x50);
                    temp.x = pos.x - o->x; temp.y = pos.y - o->y; temp.z = pos.z - o->z;
                }
                func_0038CF68(motion, &temp, *(float *)(motion + 0x2C) - *(float *)(state + 0x30));
                func_0038CF68(&step, motion, 1.0f);
            }
        }
        {
            float f = *(float *)(motion + 0x2C);
            float factor = (f - *(float *)(state + 0x30)) / f;
            speed += *(float *)(state + 0x44) * *(float *)(state + 0x3C);
            total += speed;
            func_0038CE20(&hit, &step, speed * factor);
        }
        pos.x += hit.x; pos.y += hit.y; pos.z += hit.z;
    }
    if (D_L39_002412DC == 0x30 || D_L39_002412DC == 0x1C) {
        if (changed) D_L39_0024B868[m->index] &= ~0x20;
    }
    return result;
}
