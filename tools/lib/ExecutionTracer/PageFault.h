/*
 * S2E Selective Symbolic Execution Framework
 *
 * Copyright (c) 2010, Dependable Systems Laboratory, EPFL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Dependable Systems Laboratory, EPFL nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE DEPENDABLE SYSTEMS LABORATORY, EPFL BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Currently maintained by:
 *    Vitaly Chipounov <vitaly.chipounov@epfl.ch>
 *    Volodymyr Kuznetsov <vova.kuznetsov@epfl.ch>
 *
 * All contributors are listed in S2E-AUTHORS file.
 *
 */

#ifndef S2ETOOLS_EXECTRACER_PageFault_H
#define S2ETOOLS_EXECTRACER_PageFault_H

#include <s2e/Plugins/ExecutionTracers/TraceEntries.h>
#include "LogParser.h"
#include "ModuleParser.h"

namespace s2etools {

class PageFault
{
private:
    sigc::connection m_connection;

    void onItem(unsigned traceIndex,
                const s2e::plugins::ExecutionTraceItemHeader &hdr,
                void *item);

    ModuleCache *m_mc;
    LogEvents *m_events;

    bool m_trackModule;
    std::string m_module;

public:
    PageFault(LogEvents *events, ModuleCache *mc);
    ~PageFault();

    void setModule(const std::string &s) {
        m_module = s;
        m_trackModule = true;
    }

};



class PageFaultState : public ItemProcessorState
{
private:
    uint64_t m_totalPageFaults;
    uint64_t m_totalTlbMisses;

public:
    static ItemProcessorState *factory();
    PageFaultState();
    virtual ~PageFaultState();
    virtual ItemProcessorState *clone() const;
    friend class PageFault;

    uint64_t getPageFaults() const {
        return m_totalPageFaults;
    }

    uint64_t getTlbMisses() const {
        return m_totalTlbMisses;
    }
};

}
#endif

