/* functional: medium. Written from scratch from the asm (no draft; no NTSC C): args decoded as 8 register ints + 5 float regs f12-f16 + 3 stack s16 (0x1F0,0x1F8,0x200); sorted node list kept with link-pointer nodes in D_L01_00220420 like retail, incl. the stale tail pointer when the 32-node pool is full. Medium: the exact meaning of func_0038CED8/D160/DBA0 (yaw/pitch angle helpers) and of the ignore lists is inferred. Compiles; 653 diff words (register allocation, VU0 vadd/vsub scalarised, frame 0x190 vs 0x1F0) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4501E8;
typedef struct Node_4501E8 {
    u8 *m;
    f32 score;
    struct Node_4501E8 *next;
    struct Node_4501E8 **link;
    V4_4501E8 pos;
} Node_4501E8;

extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_003C4B50(f32 *);
extern void func_L01_00439880(u8 *, s32 *, s32 *);
extern f32 *func_00382348(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_003C5180(u8 *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *D_L01_0021E860[];
extern Node_4501E8 D_L01_00220420[];
extern s16 D_001A4F48;
extern s32 D_L01_001D673C;

/* target_collect: gathers the mobys of the level list (D_L01_0021E860) that lie within range fC and the
 * yaw/pitch cones (fA, fB, relaxed toward fE/fD by distance) of direction dir around pos, scores them
 * (angle and distance), line-of-sight tests them best first, stores up to max in out (best moved to
 * out[0], null terminated) with *count, and returns the best. */
u8 *func_L01_004501E8(u8 *pos, f32 *dir, s32 *count, u8 **out, s32 max, u8 **ign_a, s32 flag,
                      s32 *ign_b, f32 fA, f32 fB, f32 fC, f32 fD, f32 fE, s16 s0, s16 s1, s16 s2)
{
    V4_4501E8 v00, v10, d, v30, v40, v50, v60, v70, v80;
    s32 raw90, raw94;
    Node_4501E8 *head = 0;
    Node_4501E8 *tail = 0;
    Node_4501E8 *node;
    Node_4501E8 *n;
    Node_4501E8 *p;
    u8 *m;
    u8 *best = 0;
    f32 bestscore = 999999.0f;
    f32 yawA, pitchB;
    f32 dist, score, thr, ratio;
    f32 f20, f21, f22, f23;
    f32 *sc;
    s32 pool = 0;
    s32 i, k, isenemy, cone, special, t;

    *count = 0;
    if (s1 == -1) {
        s1 = D_001A4F48;
    }
    if (fA == 0.0f) return 0;
    if (fB == 0.0f) return 0;
    if (fC == 0.0f) return 0;

    yawA = func_0038D160(dir[0], dir[1]);
    pitchB = func_0038D160(func_0038CED8(dir), dir[2]);

    for (i = 0; (m = D_L01_0021E860[i]) != 0; i++) {
        if (s0 != 0 && m[0x31] == 0) continue;
        t = *(s16 *)(m + 0xAA);
        special = 0;
        if (t == 0x1A90 || t == 0x1ADE) special = 1;
        isenemy = func_003C4B50((f32 *)m);
        cone = 0;
        if (*(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x16 &&
            (*(u16 *)(m + 0x34) & 0x4000) && m[0x31] != 0) {
            func_L01_00439880(m, &raw90, &raw94);
            if (raw94 > 0) {
                cone = 1;
                special = 1;
            }
        }
        if (isenemy != 0 && flag == 0) continue;
        if (cone != 0 && s2 == 0) continue;
        sc = func_00382348(m);
        if ((sc == 0 || (sc[0] <= 0.0f && isenemy == 0)) && cone == 0) continue;
        if (!((*(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 5) || isenemy != 0 || cone != 0)) continue;

        if (ign_a != 0 && ign_a[0] != 0) {
            for (k = 0; ign_a[k] != 0; k++) {
                if (ign_a[k] == m) break;
            }
            if (ign_a[k] != 0) continue;
        }
        if (ign_b != 0 && ign_b[0] != -1) {
            for (k = 0; ign_b[k] != -1; k++) {
                if (ign_b[k] == t) break;
            }
            if (ign_b[k] != -1) continue;
        }

        v10 = *(V4_4501E8 *)(m + 0x10);
        if (sc != 0) {
            if (D_L01_001D673C != 0 || s1 != 0) {
                func_0038CE20(&v00, m + 0xE0, sc[4]);
                v10.x = v10.x + v00.x;
                v10.y = v10.y + v00.y;
                v10.z = v10.z + v00.z;
            } else {
                v10.z = v10.z + sc[4];
            }
        } else {
            if (D_L01_001D673C != 0 || s1 != 0) {
                func_0038CE20(&v00, m + 0xE0, *(f32 *)(m + 0xC) * 0.0009765625f);
                v10.x = v10.x + v00.x;
                v10.y = v10.y + v00.y;
                v10.z = v10.z + v00.z;
            } else {
                v10.z = v10.z + *(f32 *)(m + 0xC) * 0.0009765625f;
            }
        }
        d.x = v10.x - ((V4_4501E8 *)pos)->x;
        d.y = v10.y - ((V4_4501E8 *)pos)->y;
        d.z = v10.z - ((V4_4501E8 *)pos)->z;
        d.w = v10.w;
        dist = func_0038CEA8(&d);
        if (fC < dist) continue;
        if (dist < 0.1f) continue;
        ratio = func_L01_004451D0(-2.0f, 0.0f, 1.0f, 0.0f, dist / fC);
        f22 = 0.0f;
        f23 = 0.0f;
        if (fA < 3.1415927f || fB < 3.1415927f) {
            if (D_L01_001D673C == 0) {
                f22 = func_0038DBA0(func_0038D160(d.x, d.y), yawA);
                thr = fA;
                if (0.0f < fE) thr = fE + (fA - fE) * ratio;
                if (thr <= f22) continue;
                f23 = func_0038DBA0(func_0038D160(func_0038CED8(&d), d.z), pitchB);
            } else {
                func_003C5180(pos, &v30, 1);
                func_0038CE20(&v40, &v30, func_0038CE68(&v30, &d));
                v50.x = d.x - v40.x;
                v50.y = d.y - v40.y;
                v50.z = d.z - v40.z;
                v50.w = d.w;
                func_0038CE20(&v60, &v30, func_0038CE68(&v30, dir));
                v70.x = dir[0] - v60.x;
                v70.y = dir[1] - v60.y;
                v70.z = dir[2] - v60.z;
                v70.w = dir[3];
                f22 = func_0038CE68(&v70, &v50);
                if (f22 < 0.0f) continue;
                f21 = func_0038CEA8(&v50);
                if (f21 == 0.0f) continue;
                f20 = func_0038CEA8(&v70);
                if (f20 == 0.0f) continue;
                f22 = 1.5707964f - func_0038D0C8(f22 / (f21 * f20));
                thr = fA;
                if (0.0f < fE) thr = fE + (fA - fE) * ratio;
                if (thr <= f22) continue;
                func_0038CE20(&v80, &v50, f20 / f21);
                v80.x = v80.x + v60.x;
                v80.y = v80.y + v60.y;
                v80.z = v80.z + v60.z;
                f20 = func_0038CEA8(&v80);
                f23 = 1.5707964f - func_0038D0C8(func_0038CE68(&v80, &d) / (f20 * dist));
            }
            thr = fB;
            if (0.0f < fD) thr = fD + (fB - fD) * ratio;
            if (thr <= f23) continue;
        }
        score = f22 * 3.0f + f23 * 0.2f * dist + dist * 0.1f;
        if (isenemy != 0 || special != 0) {
            score = score * (fC * 0.8f);
        }
        if (pool < 0x20) {
            n = &D_L01_00220420[pool];
            pool++;
        } else {
            n = tail;
            *n->link = 0;
        }
        n->m = m;
        n->pos = v10;
        n->score = score;
        if (head == 0) {
            tail = n;
            head = n;
            n->link = &head;
            n->next = 0;
        } else {
            p = head;
            while (!(score < p->score)) {
                p = p->next;
                if (p == 0) break;
            }
            if (p == 0) {
                n->next = 0;
                n->link = &tail->next;
                tail->next = n;
                tail = n;
            } else {
                n->next = p;
                n->link = p->link;
                *p->link = n;
                p->link = &n->next;
            }
        }
    }

    while ((node = head) != 0) {
        m = node->m;
        if (node->score < bestscore) {
            if (func_003D3CB0(pos, &node->pos, 0x12, m, 0) != 0) {
                head = head->next;
                continue;
            }
            best = m;
            bestscore = head->score;
        }
        if (out != 0 && *count < max) {
            out[*count] = m;
            *count = *count + 1;
        }
        head = head->next;
    }

    if (out == 0) return best;
    if (best != 0) {
        u8 **q;
        u8 *first;
        i = 0;
        if (max > 0) {
            first = out[0];
            if (first != best) {
                q = out;
                for (;;) {
                    i++;
                    q++;
                    if (!(i < max)) break;
                    if (*q == best) {
                        out[0] = best;
                        *q = first;
                        break;
                    }
                }
            }
        }
        if (i == max) {
            out[0] = best;
        }
    }
    if (*count < max) {
        out[*count] = 0;
    }
    return best;
}
