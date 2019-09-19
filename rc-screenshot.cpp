#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);
	GdkPixbuf* pixbuf;
	GdkWindow* root_window;
	GError* err = NULL;
	gint x, y, width, height;
	root_window = gdk_get_default_root_window();
	if (!root_window)
		return EXIT_FAILURE;
	gdk_window_get_geometry(root_window, &x, &y, &width, &height);
	pixbuf = gdk_pixbuf_get_from_window(root_window, x, y, width, height);
	if (NULL == pixbuf)
		return EXIT_FAILURE;
	if (FALSE == gdk_pixbuf_save(pixbuf, "screenshot.jpeg",
		"jpeg", &err, "quality", "95", NULL))
	{
		g_object_unref(pixbuf);
		return EXIT_FAILURE;
	}
	g_object_unref(pixbuf);
	return EXIT_SUCCESS;
}
