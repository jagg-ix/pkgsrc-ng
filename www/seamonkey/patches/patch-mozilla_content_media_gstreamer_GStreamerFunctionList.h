$NetBSD: patch-mozilla_content_media_gstreamer_GStreamerFunctionList.h,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/content/media/gstreamer/GStreamerFunctionList.h.orig	2014-03-19 01:41:47.000000000 +0000
+++ mozilla/content/media/gstreamer/GStreamerFunctionList.h
@@ -9,7 +9,6 @@
  * List of symbol names we need to dlsym from the gstreamer library.
  */
 GST_FUNC(LIBGSTAPP, gst_app_sink_get_type)
-GST_FUNC(LIBGSTAPP, gst_app_sink_pull_buffer)
 GST_FUNC(LIBGSTAPP, gst_app_sink_set_callbacks)
 GST_FUNC(LIBGSTAPP, gst_app_src_end_of_stream)
 GST_FUNC(LIBGSTAPP, gst_app_src_get_size)
@@ -22,10 +21,8 @@ GST_FUNC(LIBGSTAPP, gst_app_src_set_stre
 GST_FUNC(LIBGSTREAMER, gst_bin_get_by_name)
 GST_FUNC(LIBGSTREAMER, gst_bin_get_type)
 GST_FUNC(LIBGSTREAMER, gst_bin_iterate_recurse)
-GST_FUNC(LIBGSTREAMER, gst_buffer_copy_metadata)
 GST_FUNC(LIBGSTREAMER, gst_buffer_get_type)
 GST_FUNC(LIBGSTREAMER, gst_buffer_new)
-GST_FUNC(LIBGSTREAMER, gst_buffer_new_and_alloc)
 GST_FUNC(LIBGSTREAMER, gst_bus_set_sync_handler)
 GST_FUNC(LIBGSTREAMER, gst_bus_timed_pop_filtered)
 GST_FUNC(LIBGSTREAMER, gst_caps_append)
@@ -37,47 +34,37 @@ GST_FUNC(LIBGSTREAMER, gst_caps_new_any)
 GST_FUNC(LIBGSTREAMER, gst_caps_new_empty)
 GST_FUNC(LIBGSTREAMER, gst_caps_new_full)
 GST_FUNC(LIBGSTREAMER, gst_caps_new_simple)
-GST_FUNC(LIBGSTREAMER, gst_caps_unref)
-GST_FUNC(LIBGSTREAMER, gst_element_factory_get_klass)
+GST_FUNC(LIBGSTREAMER, gst_caps_set_simple)
 GST_FUNC(LIBGSTREAMER, gst_element_factory_get_static_pad_templates)
 GST_FUNC(LIBGSTREAMER, gst_element_factory_get_type)
 GST_FUNC(LIBGSTREAMER, gst_element_factory_make)
 GST_FUNC(LIBGSTREAMER, gst_element_get_factory)
-GST_FUNC(LIBGSTREAMER, gst_element_get_pad)
+GST_FUNC(LIBGSTREAMER, gst_element_get_static_pad)
 GST_FUNC(LIBGSTREAMER, gst_element_get_type)
 GST_FUNC(LIBGSTREAMER, gst_element_query_convert)
 GST_FUNC(LIBGSTREAMER, gst_element_query_duration)
 GST_FUNC(LIBGSTREAMER, gst_element_seek_simple)
 GST_FUNC(LIBGSTREAMER, gst_element_set_state)
-GST_FUNC(LIBGSTREAMER, gst_event_parse_new_segment)
 GST_FUNC(LIBGSTREAMER, gst_flow_get_name)
 GST_FUNC(LIBGSTREAMER, gst_init)
 GST_FUNC(LIBGSTREAMER, gst_init_check)
 GST_FUNC(LIBGSTREAMER, gst_iterator_next)
 GST_FUNC(LIBGSTREAMER, gst_message_parse_error)
 GST_FUNC(LIBGSTREAMER, gst_message_type_get_name)
-GST_FUNC(LIBGSTREAMER, gst_mini_object_get_type)
-GST_FUNC(LIBGSTREAMER, gst_mini_object_new)
 GST_FUNC(LIBGSTREAMER, gst_mini_object_ref)
 GST_FUNC(LIBGSTREAMER, gst_mini_object_unref)
 GST_FUNC(LIBGSTREAMER, gst_object_get_name)
 GST_FUNC(LIBGSTREAMER, gst_object_get_parent)
 GST_FUNC(LIBGSTREAMER, gst_object_unref)
-GST_FUNC(LIBGSTREAMER, gst_pad_add_event_probe)
-GST_FUNC(LIBGSTREAMER, gst_pad_alloc_buffer)
 GST_FUNC(LIBGSTREAMER, gst_pad_get_element_private)
-GST_FUNC(LIBGSTREAMER, gst_pad_get_negotiated_caps)
-GST_FUNC(LIBGSTREAMER, gst_pad_set_bufferalloc_function)
 GST_FUNC(LIBGSTREAMER, gst_pad_set_element_private)
 GST_FUNC(LIBGSTREAMER, gst_parse_bin_from_description)
 GST_FUNC(LIBGSTREAMER, gst_pipeline_get_bus)
 GST_FUNC(LIBGSTREAMER, gst_pipeline_get_type)
 GST_FUNC(LIBGSTREAMER, gst_plugin_feature_get_rank)
 GST_FUNC(LIBGSTREAMER, gst_registry_feature_filter)
-GST_FUNC(LIBGSTREAMER, gst_registry_get_default)
 GST_FUNC(LIBGSTREAMER, gst_registry_get_feature_list_cookie)
 GST_FUNC(LIBGSTREAMER, gst_segment_init)
-GST_FUNC(LIBGSTREAMER, gst_segment_set_newsegment)
 GST_FUNC(LIBGSTREAMER, gst_segment_to_stream_time)
 GST_FUNC(LIBGSTREAMER, gst_static_caps_get)
 GST_FUNC(LIBGSTREAMER, gst_structure_copy)
@@ -86,11 +73,82 @@ GST_FUNC(LIBGSTREAMER, gst_structure_get
 GST_FUNC(LIBGSTREAMER, gst_structure_get_value)
 GST_FUNC(LIBGSTREAMER, gst_structure_new)
 GST_FUNC(LIBGSTREAMER, gst_util_uint64_scale)
+
+#if GST_VERSION_MAJOR == 0
+GST_FUNC(LIBGSTAPP, gst_app_sink_pull_buffer)
+GST_FUNC(LIBGSTREAMER, gst_buffer_copy_metadata)
+GST_FUNC(LIBGSTREAMER, gst_buffer_new_and_alloc)
+GST_FUNC(LIBGSTREAMER, gst_caps_unref)
+GST_FUNC(LIBGSTREAMER, gst_element_factory_get_klass)
+GST_FUNC(LIBGSTREAMER, gst_element_get_pad)
+GST_FUNC(LIBGSTREAMER, gst_event_parse_new_segment)
+GST_FUNC(LIBGSTREAMER, gst_mini_object_get_type)
+GST_FUNC(LIBGSTREAMER, gst_mini_object_new)
+GST_FUNC(LIBGSTREAMER, gst_pad_add_event_probe)
+GST_FUNC(LIBGSTREAMER, gst_pad_alloc_buffer)
+GST_FUNC(LIBGSTREAMER, gst_pad_get_negotiated_caps)
+GST_FUNC(LIBGSTREAMER, gst_pad_set_bufferalloc_function)
+GST_FUNC(LIBGSTREAMER, gst_registry_get_default)
+GST_FUNC(LIBGSTREAMER, gst_segment_set_newsegment)
 GST_FUNC(LIBGSTVIDEO, gst_video_format_get_component_height)
 GST_FUNC(LIBGSTVIDEO, gst_video_format_get_component_offset)
 GST_FUNC(LIBGSTVIDEO, gst_video_format_get_component_width)
+GST_FUNC(LIBGSTVIDEO, gst_video_format_get_pixel_stride)
 GST_FUNC(LIBGSTVIDEO, gst_video_format_get_row_stride)
 GST_FUNC(LIBGSTVIDEO, gst_video_format_parse_caps)
+#else
+
+GST_FUNC(LIBGSTAPP, gst_app_sink_pull_sample)
+GST_FUNC(LIBGSTREAMER, _gst_caps_any)
+GST_FUNC(LIBGSTREAMER, gst_allocator_get_type)
+GST_FUNC(LIBGSTREAMER, gst_buffer_copy_into)
+GST_FUNC(LIBGSTREAMER, gst_buffer_extract)
+GST_FUNC(LIBGSTREAMER, gst_buffer_get_meta)
+GST_FUNC(LIBGSTREAMER, gst_buffer_get_size)
+GST_FUNC(LIBGSTREAMER, gst_buffer_map)
+GST_FUNC(LIBGSTREAMER, gst_buffer_new_allocate)
+GST_FUNC(LIBGSTREAMER, gst_buffer_n_memory)
+GST_FUNC(LIBGSTREAMER, gst_buffer_peek_memory)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_acquire_buffer)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_config_set_allocator)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_config_set_params)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_get_config)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_get_type)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_is_active)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_set_active)
+GST_FUNC(LIBGSTREAMER, gst_buffer_pool_set_config)
+GST_FUNC(LIBGSTREAMER, gst_buffer_set_size)
+GST_FUNC(LIBGSTREAMER, gst_buffer_unmap)
+GST_FUNC(LIBGSTREAMER, gst_element_factory_get_metadata)
+GST_FUNC(LIBGSTREAMER, gst_event_parse_segment)
+GST_FUNC(LIBGSTREAMER, gst_memory_init)
+GST_FUNC(LIBGSTREAMER, gst_memory_map)
+GST_FUNC(LIBGSTREAMER, gst_memory_unmap)
+GST_FUNC(LIBGSTREAMER, gst_object_get_type)
+GST_FUNC(LIBGSTREAMER, gst_pad_add_probe)
+GST_FUNC(LIBGSTREAMER, gst_pad_get_current_caps)
+GST_FUNC(LIBGSTREAMER, gst_pad_probe_info_get_query)
+GST_FUNC(LIBGSTREAMER, gst_query_add_allocation_meta)
+GST_FUNC(LIBGSTREAMER, gst_query_add_allocation_param)
+GST_FUNC(LIBGSTREAMER, gst_query_add_allocation_pool)
+GST_FUNC(LIBGSTREAMER, gst_query_parse_allocation)
+GST_FUNC(LIBGSTREAMER, gst_registry_get)
+GST_FUNC(LIBGSTREAMER, gst_sample_get_buffer)
+GST_FUNC(LIBGSTREAMER, gst_segment_copy_into)
+GST_FUNC(LIBGSTREAMER, gst_structure_free)
+GST_FUNC(LIBGSTVIDEO, gst_buffer_pool_config_get_video_alignment)
+GST_FUNC(LIBGSTVIDEO, gst_buffer_pool_has_option)
+GST_FUNC(LIBGSTVIDEO, gst_video_buffer_pool_get_type)
+GST_FUNC(LIBGSTVIDEO, gst_video_frame_map)
+GST_FUNC(LIBGSTVIDEO, gst_video_frame_unmap)
+GST_FUNC(LIBGSTVIDEO, gst_video_info_align)
+GST_FUNC(LIBGSTVIDEO, gst_video_info_from_caps)
+GST_FUNC(LIBGSTVIDEO, gst_video_info_init)
+GST_FUNC(LIBGSTVIDEO, gst_video_meta_api_get_type)
+GST_FUNC(LIBGSTVIDEO, gst_video_meta_map)
+GST_FUNC(LIBGSTVIDEO, gst_video_meta_unmap)
+
+#endif
 
 /*
  * Functions that have been defined in the header file. We replace them so that
@@ -100,6 +158,11 @@ GST_FUNC(LIBGSTVIDEO, gst_video_format_p
 REPLACE_FUNC(gst_buffer_ref);
 REPLACE_FUNC(gst_buffer_unref);
 REPLACE_FUNC(gst_message_unref);
+
+#if GST_VERSION_MAJOR == 1
+REPLACE_FUNC(gst_caps_unref);
+REPLACE_FUNC(gst_sample_unref);
+#endif
 #endif
 
 #endif // !defined(__APPLE__)
