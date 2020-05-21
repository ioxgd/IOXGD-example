{
	"font": [
		{
			"name": "Roboto_16",
			"size": 16,
			"range": "0x0020-0x007F",
			"variable": "lv_font_roboto_16",
			"file": "font/Roboto-Regular.ttf"
		},
		{
			"name": "supermarket_30",
			"file": "C:\\Users\\Max\\Desktop\\newVersionPage\\supermarket.ttf",
			"size": 30,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		},
		{
			"name": "supermarket_80",
			"file": "C:\\Users\\Max\\Desktop\\newVersionPage\\supermarket.ttf",
			"size": 80,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		}
	],
	"page": [
		{
			"name": "index",
			"background": {
				"main_color": "#EAEDED",
				"grad_color": "#EAEDED"
			},
			"component": {
				"component-0": {
					"name": "Object",
					"property": {
						"name": "box1",
						"parent": "",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": -240,
						"y": 20,
						"width": 280,
						"height": 210,
						"main_color": "#FFFFFF",
						"grad_color": "#FFFFFF",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 4,
						"shadow_color": "#AFAFAF",
						"shadow_type": 0
					}
				},
				"component-2": {
					"name": "Object",
					"property": {
						"name": "box1in",
						"parent": "box1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": 0,
						"width": 280,
						"height": 160,
						"main_color": "#1ABC9C",
						"grad_color": "#1ABC9C",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				},
				"component-3": {
					"name": "Label",
					"property": {
						"name": "txt1",
						"parent": "box1",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 10,
						"width": 0,
						"height": 0,
						"text": "อุณหภูมิ (*C)",
						"text_align": 0,
						"color": "#515A5A",
						"mode": 0,
						"font": "supermarket_30"
					}
				},
				"component-4": {
					"name": "Object",
					"property": {
						"name": "box2",
						"parent": "",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": 60,
						"y": 20,
						"width": 280,
						"height": 210,
						"main_color": "#FFFFFF",
						"grad_color": "#FFFFFF",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 4,
						"shadow_color": "#AFAFAF",
						"shadow_type": 0
					}
				},
				"component-5": {
					"name": "Object",
					"property": {
						"name": "box2in",
						"parent": "box2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": 0,
						"width": 280,
						"height": 160,
						"main_color": "#F1C40F",
						"grad_color": "#F1C40F",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				},
				"component-6": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"parent": "box2",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 10,
						"width": 0,
						"height": 0,
						"text": "ความชื้น (%RH)",
						"text_align": 0,
						"color": "#515A5A",
						"mode": 0,
						"font": "supermarket_30"
					}
				},
				"component-7": {
					"name": "Object",
					"property": {
						"name": "box3",
						"parent": "",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": 300,
						"y": 20,
						"width": 160,
						"height": 210,
						"main_color": "#FFFFFF",
						"grad_color": "#FFFFFF",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 4,
						"shadow_color": "#AFAFAF",
						"shadow_type": 0
					}
				},
				"component-9": {
					"name": "Label",
					"property": {
						"name": "txt3",
						"parent": "box3",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 10,
						"width": 0,
						"height": 0,
						"text": "ไฟหน้าบ้าน",
						"text_align": 0,
						"color": "#515A5A",
						"mode": 0,
						"font": "supermarket_30"
					}
				},
				"component-10": {
					"name": "Label",
					"property": {
						"name": "temp",
						"parent": "box1in",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 0,
						"width": 0,
						"height": 0,
						"text": "200",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_80"
					}
				},
				"component-12": {
					"name": "Label",
					"property": {
						"name": "humi",
						"parent": "box2in",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 0,
						"width": 0,
						"height": 0,
						"text": "10",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_80"
					}
				},
				"component-13": {
					"name": "Object",
					"property": {
						"name": "box4",
						"parent": "",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -20,
						"width": 760,
						"height": 210,
						"main_color": "#FFFFFF",
						"grad_color": "#FFFFFF",
						"radius": 0,
						"opacity": 255,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 4,
						"shadow_color": "#AFAFAF",
						"shadow_type": 0
					}
				},
				"component-14": {
					"name": "Chart",
					"property": {
						"name": "chart1",
						"parent": "box4",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 0,
						"width": 740,
						"height": 190,
						"range_min": 0,
						"range_max": 100,
						"division_h": 5,
						"division_v": 10,
						"background_main_color": "#FFFFFF",
						"background_grad_color": "#FFFFFF",
						"border_width": 0,
						"border_color": "#404040",
						"radius": 6,
						"line_width": 2,
						"line_color": "#E5E7E9",
						"series_width": 2
					}
				},
				"component-15": {
					"name": "Switch",
					"property": {
						"name": "lamp",
						"parent": "box3",
						"hidden": 1,
						"define": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 20,
						"width": 100,
						"height": 60,
						"padding": 0,
						"background_main_color": "#FFFFFF",
						"background_grad_color": "#FFFFFF",
						"background_border_width": 2,
						"background_border_color": "#E5E7E9",
						"indicator_main_color": "#A569BD",
						"indicator_grad_color": "#A569BD",
						"indicator_border_width": 2,
						"indicator_border_color": "#5B2C6F",
						"knob_on_main_color": "#8E44AD",
						"knob_on_grad_color": "#8E44AD",
						"knob_on_border_width": 2,
						"knob_on_border_color": "#5B2C6F",
						"knob_off_main_color": "#FFFFFF",
						"knob_off_grad_color": "#FFFFFF",
						"knob_off_border_width": 2,
						"knob_off_border_color": "#D7DBDD",
						"knob_shadow_width": 0,
						"knob_shadow_color": "#808080",
						"value": 0,
						"handler": "event_helper_handle"
					}
				},
				"component-16": {
					"name": "Object",
					"property": {
						"name": "loadingBox",
						"parent": "",
						"hidden": 0,
						"define": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 0,
						"width": 800,
						"height": 480,
						"main_color": "#000000",
						"grad_color": "#000000",
						"radius": 0,
						"opacity": 160,
						"border_width": 0,
						"border_color": "#000000",
						"border_opacity": 255,
						"shadow_width": 0,
						"shadow_color": "#000000",
						"shadow_type": 1
					}
				},
				"component-17": {
					"name": "Label",
					"property": {
						"name": "txt4",
						"parent": "loadingBox",
						"hidden": 1,
						"define": 0,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 0,
						"width": 0,
						"height": 0,
						"text": "LOADING",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_80"
					}
				}
			}
		}
	]
}