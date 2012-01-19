/*
 *  Copyright (C) 2012 Leandro Nini
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef C64_H
#define C64_H

#include "sidplayfp/c64env.h"
#include "sidplayfp/c64/c64cpu.h"
#include "sidplayfp/c64/c64cia.h"
#include "sidplayfp/c64/c64vic.h"
#include "sidplayfp/c64/mmu.h"

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef PC64_TESTSUITE
#  include <string.h>
#endif


class sidemu;

SIDPLAY2_NAMESPACE_START

class c64: private c64env
{
public:
    static const float64_t CLOCK_FREQ_NTSC;
    static const float64_t CLOCK_FREQ_PAL;

    static const int MAX_SIDS = 2;

private:
    static const float64_t VIC_FREQ_PAL;
    static const float64_t VIC_FREQ_NTSC;

    static const int MAPPER_SIZE = 32;

private:
    /** System clock frequency */
    float64_t m_cpuFreq;

    /** Number of sources asserting IRQ */
    int   irqCount;

    /** BA state */
    bool oldBAState;

    /** System event context */
    EventScheduler m_scheduler;

    /** CPU */
    c64cpu  cpu;

    /** CIA1 */
    c64cia1 cia1;

    /** CIA2 */
    c64cia2 cia2;

    /** VIC */
    c64vic  vic;

    /** SID chips */
    sidemu *sid[MAX_SIDS];

    /** SID mapping table in d4xx-d7xx */
    int     sidmapper[32];

    /** MMU chip */
    MMU     mmu;

private:
    uint8_t readMemByte_io   (const uint_least16_t addr);
    void    writeMemByte_io  (const uint_least16_t addr, const uint8_t data);

    uint8_t m_readMemByte    (const uint_least16_t);
    void    m_writeMemByte   (const uint_least16_t, const uint8_t);

    /**
    * Access memory as seen by CPU.
    *
    * @param address
    * @return value at address
    */
    uint8_t cpuRead  (const uint_least16_t addr) { return m_readMemByte (addr); }

    /**
    * Access memory as seen by CPU.
    *
    * @param address
    * @param value
    */
    void    cpuWrite (const uint_least16_t addr, const uint8_t data) { m_writeMemByte (addr, data); }

    /**
    * IRQ trigger signal.
    *
    * Calls permitted any time, but normally originated by chips at PHI1.
    *
    * @param state
    */
    inline void interruptIRQ (const bool state);

    /**
    * NMI trigger signal.
    *
    * Calls permitted any time, but normally originated by chips at PHI1.
    *
    * @param state
    */
    inline void interruptNMI (void) { cpu.triggerNMI (); }

    inline void interruptRST (void) { /*stop ();*/ }

    /**
    * BA signal.
    *
    * Calls permitted during PHI1.
    *
    * @param state
    */
    inline void setBA (const bool state);

    inline void lightpen () { vic.lightpen (); }

#ifdef PC64_TESTSUITE
    void   loadFile (const char *file)
    {
        /*char name[0x100] = PC64_TESTSUITE;
        strcat (name, file);
        strcat (name, ".prg");

        m_tune->load (name);
        stop ();*/
    }
#endif

public:
    c64();
    ~c64() {}

    /**
    * Get C64's event scheduler
    *
    * @return the scheduler
    */
    EventScheduler *getEventScheduler() { return &m_scheduler; }
    //const EventScheduler &getEventScheduler() const { return m_scheduler; }

    void debug(const bool enable, FILE *out) { cpu.debug (enable, out); }

    void reset();
    void resetCpu() { cpu.reset(); }

    void setMainCpuSpeed(const float64_t cpuFreq);
    float64_t getMainCpuSpeed() const { return m_cpuFreq; }

    /**
    * Set the requested SID
    *
    * @param i sid number to set
    * @param sidemu the sid to set
    */
    void setSid(const int i, sidemu *s) { sid[i] = s; }

    /**
    * Return the requested SID
    *
    * @param i sid number to get
    * @return the SID
    */
    sidemu *getSid(const int i) const { return sid[i]; }

    void resetSIDMapper();
    void setSecondSIDAddress(const int sidChipBase2);

    /**
    * Get the components credits
    */
    //@{
    const char* cpuCredits () { return cpu.credits(); }
    const char* ciaCredits () { return cia1.credits(); }
    const char* vicCredits () { return vic.credits(); }
    //@}

    MMU *getMmu() { return &mmu; } //FIXME
};

void c64::interruptIRQ (const bool state)
{
    if (state)
    {
        if (irqCount == 0)
            cpu.triggerIRQ ();

        irqCount ++;
    }
    else
    {
        irqCount --;
        if (irqCount == 0)
             cpu.clearIRQ ();
    }
}

void c64::setBA (const bool state) {
    /* only react to changes in state */
    if (state ^ oldBAState == false)
        return;

    oldBAState = state;

    /* Signal changes in BA to interested parties */
    cpu.setRDY (state);
}

SIDPLAY2_NAMESPACE_STOP

#endif // C64_H