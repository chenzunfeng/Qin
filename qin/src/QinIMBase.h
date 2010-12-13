/**
 * @file   QinIMBase.h
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2010 -  Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __QIN_SRC_QIN_IM_BASE_H__
#define __QIN_SRC_QIN_IM_BASE_H__

#include <QHash>

#define QIN_KEYMAP_REG(a, b) \
  toStdKB[a] = b; \
  fromStdKB[b] = a;

#define QIN_SHIFT_KEYMAP_REG(a, b) \
  ShiftToStdKB[a] = b; \
  ShiftFromStdKB[b] = a;

class QinIMBase {
  private:
    bool useCustomKeyMap;
    bool preEditable;

  public:
    /** Public members **/
    QHash<QString, QString> toStdKB;
    QHash<QString, QString> fromStdKB;

    /** Public methods **/
    QinIMBase(bool ukey = false, bool pre = false):
      useCustomKeyMap(ukey), preEditable(pre) {}
    virtual ~QinIMBase() {}
    void setUseCustomKeyMap(bool s) { useCustomKeyMap = s; }
    bool getUseCustomKeyMap(void) { return useCustomKeyMap; }
    void setPreEditable(bool s) { preEditable = s; }
    bool getPreEditable(void) { return preEditable; }

    virtual void setupAll(void) { setupKeyMap(); };
    virtual void setupKeyMap(void) {}

    /** I/O related **/
    /* Caller must free it */
    virtual char* getPreEditString(void) { return NULL; }
    void reset(void) {}

    /** Key handling APIs **/
    virtual void handle_Default(int) {}
    virtual void handle_Space(void) {}
    virtual void handle_Esc(void) {}
    virtual void handle_Enter(void) {}
    virtual void handle_Del(void) {}
    virtual void handle_Backspace(void) {}
    virtual void handle_Tab(void) {}
    virtual void handle_ShiftLeft(void) {}
    virtual void handle_Left(void) {}
    virtual void handle_ShiftRight(void) {}
    virtual void handle_Right(void) {}
    virtual void handle_Up(void) {}
    virtual void handle_Home(void) {}
    virtual void handle_End(void) {}
    virtual void handle_PageUp(void) {}
    virtual void handle_PageDown(void) {}
    virtual void handle_Down(void) {}
    virtual void handle_Capslock(void) {}
};

#endif /* __QIN_SRC_QIN_IM_BASE_H__ */
