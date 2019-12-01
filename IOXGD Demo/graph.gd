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
			"file": "C:\\Users\\Max\\Downloads\\supermarket (3)\\supermarket-1-1\\supermarket.ttf",
			"size": 30,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
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
				"main_color": "#707B7C",
				"grad_color": "#707B7C"
			},
			"component": {
				"component-1": {
					"name": "Button",
					"property": {
						"name": "btn1",
						"hidden": 1,
						"alignX": 0,
						"alignY": 0,
						"x": 0,
						"y": 0,
						"width": 120,
						"height": 80,
						"toggle": 0,
						"text": "< Back",
						"rel_main_color": "#515A5A",
						"rel_grad_color": "#515A5A",
						"pr_main_color": "#4D5656",
						"pr_grad_color": "#4D5656",
						"border_width": 0,
						"border_color": "#0B1928",
						"radius": 0,
						"color": "#FFFFFF",
						"font": "supermarket_30"
					}
				},
				"component-2": {
					"name": "Chart",
					"property": {
						"name": "chart1",
						"hidden": 1,
						"alignX": 0,
						"alignY": 0,
						"x": 50,
						"y": 130,
						"width": 700,
						"height": 260,
						"range_min": 0,
						"range_max": 100,
						"division_h": 3,
						"division_v": 10,
						"background_main_color": "#FFFFFF",
						"background_grad_color": "#C0C0C0",
						"border_width": 2,
						"border_color": "#404040",
						"radius": 6,
						"line_width": 2,
						"line_color": "#202020",
						"series_width": 2
					}
				},
				"component-3": {
					"name": "Label",
					"property": {
						"name": "txt2",
						"hidden": 1,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 10,
						"width": 0,
						"height": 0,
						"text": "กราฟ",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 0,
						"font": "supermarket_60"
					}
				},
				"component-4": {
					"name": "Slider",
					"property": {
						"name": "slider1",
						"hidden": 1,
						"alignX": 1,
						"alignY": 2,
						"x": 0,
						"y": -20,
						"width": 400,
						"height": 40,
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
						"indicator_padding": 0,
						"knob_main_color": "#6b9ac7",
						"knob_grad_color": "#2b598b",
						"knob_border_width": 2,
						"knob_border_color": "#152c42",
						"value": 50,
						"range_min": 0,
						"range_max": 100
					}
				}
			}
		}
	]
}