#pragma once

#include <napa/providers/logging.h>

#include <stdarg.h>

namespace napa {
namespace providers {

    /// <summary> A logging provider that logs to the standard console. </summary>
    class ConsoleLoggingProvider : public LoggingProvider {
    public:

        virtual void Log(const char* section,
                         Verboseness level,
                         const char* traceId,
                         const char* format, ...) override {
            printf_s("[%s] ", section);
            
            va_list vl;
            va_start(vl, format);
            vfprintf_s(stdout, format, vl);
            va_end(vl);

            printf_s("\n");
        }

        virtual bool IsLogEnabled(const char* section, Verboseness level) override {
            return true;
        }

        virtual void Destroy() override {
            // Don't actually delete. We're a lifetime process object.
        }
    };

}
}