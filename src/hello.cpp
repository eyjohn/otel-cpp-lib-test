#include <hello.h>
#include <opentelemetry/trace/provider.h>
#include <opentelemetry/trace/tracer_provider.h>
#include <iostream>

namespace {
opentelemetry::nostd::shared_ptr<opentelemetry::trace::Tracer> get_tracer()
{
    return opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("hello");
}
}

void hello()
{
    auto tracer = get_tracer();
    tracer->StartSpan("hello", { { "who", "world" } }, { { tracer->GetCurrentSpan()->GetContext(), {} } });
    std::cout << "hello world!" << std::endl;
}
