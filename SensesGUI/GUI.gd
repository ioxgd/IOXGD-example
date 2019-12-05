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
			"name": "supermarket_60",
			"file": "C:\\Users\\Max\\Downloads\\supermarket (3)\\supermarket-1-1\\supermarket.ttf",
			"size": 60,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		}
	],
	"page": [
		{
			"name": "index",
			"background": {
				"main_color": "#474747",
				"grad_color": "#2E2E2E"
			},
			"component": {
				"component-0": {
					"name": "Slider",
					"property": {
						"name": "slider",
						"hidden": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": 40,
						"width": 400,
						"height": 50,
						"background_main_color": "#FFFFFF",
						"background_grad_color": "#C0C0C0",
						"background_border_width": 2,
						"background_border_color": "#404040",
						"background_radius": 6,
						"background_padding": 6,
						"indicator_main_color": "#6b9ac7",
						"indicator_grad_color": "#2b598b",
						"indicator_border_width": 2,
						"indicator_border_color": "#152c42",
						"indicator_radius": 6,
						"indicator_padding": 6,
						"knob_main_color": "#6b9ac7",
						"knob_grad_color": "#2b598b",
						"knob_border_width": 2,
						"knob_border_color": "#152c42",
						"value": 0,
						"range_min": 0,
						"range_max": 100
					}
				},
				"component-1": {
					"name": "Label",
					"property": {
						"name": "txtValue",
						"hidden": 1,
						"alignX": 1,
						"alignY": 1,
						"x": 0,
						"y": -30,
						"width": 0,
						"height": 0,
						"text": "0",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_60"
					}
				},
				"component-2": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"hidden": 1,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 20,
						"width": 0,
						"height": 0,
						"text": "ส่งข้อมูลขึ้น SENSES IoT",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_60"
					}
				},
				"component-3": {
					"name": "Button",
					"property": {
						"name": "btn1",
						"hidden": 1,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -60,
						"width": 160,
						"height": 60,
						"toggle": 0,
						"text": "Send",
						"rel_main_color": "#76A2D0",
						"rel_grad_color": "#193A5D",
						"pr_main_color": "#336294",
						"pr_grad_color": "#10263C",
						"border_width": 2,
						"border_color": "#0B1928",
						"radius": 6,
						"color": "#FFFFFF",
						"font": "Roboto_16"
					}
				},
				"component-4": {
					"name": "Label",
					"property": {
						"name": "txtStatus",
						"hidden": 1,
						"alignX": 1,
						"alignY": 2,
						"x": 10,
						"y": -20,
						"width": 0,
						"height": 0,
						"text": "wait boot finish",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "Roboto_16"
					}
				}
			}
		}
	]
}