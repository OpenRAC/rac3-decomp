/* functional: high. Same reads, writes and calls as retail; stack frame and candidate-list bookkeeping are plain C. The 0x19E6 byte-table decode is computed in a local instead of through the dead stack scratch words. */
typedef struct Cand_005BB950 {
    u8 *obj;
    f32 score;
    struct Cand_005BB950 *next;
    struct Cand_005BB950 **prev;
    f32 pos[4];
} Cand_005BB950;

typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} VT_005BB950;
typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_005BB950 *vt;
    u8 pad18[0x19E6 - 0x18];
    u8 b19E6;
} T_005BB950;

extern u8 *D_L39_00264D68[];
extern Cand_005BB950 D_L39_002943C0[];
extern u8 D_L39_004997E0[];

extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern f32 *func_00382348(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_005B8928(u8 *);
extern T_005BB950 *func_L39_0061D7B0(u8 *);

u8 *func_L39_005BB950(f32 *org, f32 *dir, s32 mode, s32 *count, u8 **out, s32 max, u8 **excl, s32 flag,
                      s16 *ids, s16 req, f32 aLim, f32 bLim, f32 maxDist, f32 aMin, f32 bMin) {
    f32 dummy[5];
    f32 pos[4];
    f32 d[4];
    Cand_005BB950 *head;
    Cand_005BB950 *tail;
    Cand_005BB950 *e;
    Cand_005BB950 *p;
    u8 *best;
    u8 *obj;
    T_005BB950 *t;
    f32 *r;
    f32 heading, pitch, dist, w, angA, angB, score, thr, lim;
    s32 poolUsed;
    s32 i, k, j, s18, s19, extra, dec;
    u8 tmp[8];
    u32 w0, w1;

    dummy[0] = 1.0f;
    dummy[4] = 0.0f;
    head = 0;
    best = 0;
    poolUsed = 0;
    tail = 0;
    *count = 0;
    thr = 1000000.0f;

    if (aLim == 0.0f) {
        return 0;
    }
    if (bLim == 0.0f) {
        return 0;
    }
    if (maxDist == 0.0f) {
        return 0;
    }

    heading = func_0038D160(dir[0], dir[1]);
    pitch = func_0038D160(func_0038CED8(dir), dir[2]);

    i = 0;
    do {
        obj = D_L39_00264D68[i];
        i++;
        if (obj == 0) {
            continue;
        }
        if (req != 0) {
            if (obj[0x31] == 0) {
                continue;
            }
        }
        if (!(*(u16 *)(obj + 0x34) & 0x1000)) {
            continue;
        }
        if (mode == 0) {
            if (obj[0xBE] & 0x10) {
                continue;
            }
        } else if (mode == 1) {
            if (obj[0xBE] & 0x8) {
                continue;
            }
        }
        s18 = func_L39_005B8928(obj);
        s19 = (*(s16 *)(obj + 0xAA) == 0x1099);
        if (s18 != 0) {
            if (flag == 0) {
                continue;
            }
        }
        t = func_L39_0061D7B0(obj);
        extra = 0;
        if (t != 0) {
            if ((t->b3 & 0xF) == 0) {
                dec = 0;
                if (t->b19E6 != 0) {
                    u32 addr = (u32)&t->b19E6;
                    k = (addr - t->b19E6) & 7;
                    for (j = 0; j < 8; j++) {
                        tmp[j] = D_L39_004997E0[((k + 5 * j) & 7) * 255 + (t->b19E6 + 1)];
                    }
                    w0 = tmp[0] | (tmp[1] << 8) | (tmp[2] << 16) | ((u32)tmp[3] << 24);
                    w1 = tmp[4] | (tmp[5] << 8) | (tmp[6] << 16) | ((u32)tmp[7] << 24);
                    w0 ^= addr;
                    dec = (s32)(w1 ^ w0);
                }
                if (dec == 0x14) {
                    continue;
                }
                extra = 1;
            }
            if (t->vt->f1C(t, mode) != 0) {
                continue;
            }
            if (*(s16 *)(obj + 0xAA) == 0x109D) {
                if (t->vt->f1C(t, -1) != 0) {
                    continue;
                }
            }
        }
        if (s19 == 0) {
            r = func_00382348(obj);
        } else {
            r = dummy;
        }
        if (r == 0) {
            continue;
        }
        if (r[0] <= 0.0f) {
            if (s18 == 0) {
                continue;
            }
        }
        {
            u8 *o24 = *(u8 **)(obj + 0x24);
            if (!(o24 != 0 && o24[0x46] == 5)) {
                if (s18 == 0) {
                    if (s19 == 0) {
                        continue;
                    }
                }
            }
        }
        if (excl != 0) {
            u8 **q = excl;
            u8 **found = 0;
            while (*q != 0) {
                if (*q == obj) {
                    found = q;
                    break;
                }
                q++;
            }
            if (found != 0) {
                continue;
            }
        }
        if (ids != 0) {
            s32 id0 = ((s32 *)ids)[0];
            if (id0 != -1) {
                s32 hid = *(s16 *)(obj + 0xAA);
                s32 *q = (s32 *)ids;
                s32 idx = 0;
                if (hid != id0) {
                    for (;;) {
                        q++;
                        if (*q == -1) {
                            idx = -1;
                            break;
                        }
                        idx++;
                        if (hid == *q) {
                            break;
                        }
                    }
                }
                if (idx >= 0) {
                    continue;
                }
            }
        }
        {
            f32 *op = (f32 *)(obj + 0x10);
            pos[0] = op[0];
            pos[1] = op[1];
            pos[2] = op[2];
            pos[3] = op[3];
        }
        if (*(f32 *)(obj + 0xE8) < 0.95f) {
            func_0038CE20(d, obj + 0xE0, r[4]);
            pos[0] += d[0];
            pos[1] += d[1];
            pos[2] += d[2];
        } else {
            pos[2] += r[4];
        }
        d[0] = pos[0] - org[0];
        d[1] = pos[1] - org[1];
        d[2] = pos[2] - org[2];
        d[3] = pos[3];
        dist = func_0038CEA8(d);
        if (maxDist < dist) {
            continue;
        }
        if (dist < 0.1f) {
            continue;
        }
        w = func_L01_004451D0(-2.0f, 0.0f, 1.0f, 0.0f, dist / maxDist);
        angA = 0.0f;
        angB = 0.0f;
        if (aLim < 3.1415927f || bLim < 3.1415927f) {
            angA = func_0038DBA0(func_0038D160(d[0], d[1]), heading);
            lim = aLim;
            if (0.0f < aMin) {
                lim = aMin + (aLim - aMin) * w;
            }
            if (lim <= angA) {
                continue;
            }
            angB = func_0038DBA0(func_0038D160(func_0038CED8(d), d[2]), pitch);
            lim = bLim;
            if (0.0f < bMin) {
                lim = bMin + (bLim - bMin) * w;
            }
            if (lim <= angB) {
                continue;
            }
        }
        score = dist + angA * dist + angB * dist;
        if (s18 != 0) {
            score += 8.0f;
        }
        if (extra != 0) {
            score += -8.0f;
        }
        if (poolUsed < 32) {
            e = &D_L39_002943C0[poolUsed];
            poolUsed++;
        } else {
            e = tail;
            *e->prev = 0;
        }
        e->obj = obj;
        e->pos[0] = pos[0];
        e->pos[1] = pos[1];
        e->pos[2] = pos[2];
        e->pos[3] = pos[3];
        e->score = score;
        if (head == 0) {
            tail = e;
            head = e;
            e->prev = &head;
            e->next = 0;
        } else {
            p = head;
            for (;;) {
                if (score < p->score) {
                    e->next = p;
                    e->prev = p->prev;
                    *p->prev = e;
                    p->prev = &e->next;
                    break;
                }
                p = p->next;
                if (p == 0) {
                    e->next = 0;
                    tail->next = e;
                    e->prev = &tail->next;
                    tail = e;
                    break;
                }
            }
        }
    } while (i < 0x100);

    while (head != 0) {
        p = head;
        if (p->score < thr) {
            obj = p->obj;
            if (func_003D3CB0(org, p->pos, 0x12, obj, 0) == 0) {
                best = obj;
                thr = head->score;
                if (out != 0) {
                    if (*count < max) {
                        out[*count] = obj;
                        (*count)++;
                    }
                }
            }
        }
        head = head->next;
    }

    if (out != 0) {
        if (best != 0) {
            s32 idx = 0;
            if (max > 0 && out[0] != best) {
                u8 *first = out[0];
                idx = 1;
                while (idx < max) {
                    if (out[idx] == best) {
                        out[0] = best;
                        out[idx] = first;
                        break;
                    }
                    idx++;
                }
            }
            if (idx == max) {
                out[0] = best;
            }
        }
        if (*count < max) {
            out[*count] = 0;
        }
    }
    return best;
}
