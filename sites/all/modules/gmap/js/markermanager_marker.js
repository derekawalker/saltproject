/**
 * @file
 * GMap Markers
 * Gmaps Utility Library MarkerManager API version
 */

/*global Drupal, GMarker, MarkerManager */

// Replace to override marker creation
Drupal.gmap.factory.marker = function (opts) {
    return new google.maps.Marker(opts);
};

Drupal.gmap.addHandler('gmap', function (elem) {
    var obj = this;

    obj.bind('init', function () {

        // Set up the markermanager.
        obj.mm = new MarkerManager(obj.map, Drupal.settings.gmap_markermanager);

        google.maps.event.addListener(obj.mm, 'loaded', function () {

            for (var i in obj.vars.markers) {

                var marker = obj.vars.markers[i];

                var minzoom = Drupal.settings.gmap_markermanager.markerMinZoom;
                var maxzoom = Drupal.settings.gmap_markermanager.markerMaxZoom;
                if (marker.minzoom) {
                    minzoom = marker.minzoom;
                }
                if (marker.maxzoom) {
                    maxzoom = marker.maxzoom;
                }
                if (maxzoom > 0) {
                    obj.mm.addMarker(marker.marker, minzoom, maxzoom);
                }
                else {
                    obj.mm.addMarker(marker.marker, minzoom);
                }
                obj.mm.refresh();

            }

        });

    });

    obj.bind('delmarker', function (marker) {
        obj.mm.removeMarker(marker.marker);
    });

    obj.bind('clearmarkers', function () {
        obj.mm.clearMarkers();
    });
});
