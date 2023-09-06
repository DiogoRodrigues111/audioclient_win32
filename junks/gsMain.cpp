#include <iostream>
#include <gst/gst.h>

int main(int argc, char* argv[])
{
    GError *error;
    GstElement *pipeline_elem = gst_parse_launch("playbin uri=file:///build/untitled.wav", &error);

    gst_init(&argc, &argv);

    if (!pipeline_elem) {
        std::cerr << "Failed to init pipeline. " << error->message << std::endl;
        g_error_free(error);
        return -1;
    }

    gst_element_set_state(pipeline_elem, GST_STATE_PLAYING);

    GMainLoop* main_looping = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(main_looping);




    /// clear up

    gst_element_set_state(pipeline_elem, GST_STATE_NULL);
    g_object_unref(pipeline_elem);
    g_main_loop_unref(main_looping);

    return 0;
}