#include <world.h>
#include <opentelemetry/trace/provider.h>
#include <opentelemetry/trace/tracer_provider.h>
#include <iostream>

namespace {
opentelemetry::nostd::shared_ptr<opentelemetry::trace::Tracer> get_tracer()
{
    return opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("world");
}
}

void world()
{
    auto tracer = get_tracer();
    tracer->StartSpan("world", { { "what", "hello" } }, { { tracer->GetCurrentSpan()->GetContext(), {} } });
    std::cout << "world, hello!" << std::endl;
}
