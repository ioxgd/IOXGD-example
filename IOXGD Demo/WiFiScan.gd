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
		},
		{
			"name": "supermarket_30",
			"file": "C:\\Users\\Max\\Downloads\\supermarket (3)\\supermarket-1-1\\supermarket.ttf",
			"size": 30,
			"range": "0x0020-0x007F,0x0E00-0x0E7F"
		}
	],
	"page": [
		{
			"name": "index",
			"background": {
				"main_color": "#2C3E50",
				"grad_color": "#2C3E50"
			},
			"component": {
				"component-0": {
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
						"rel_main_color": "#273746",
						"rel_grad_color": "#273746",
						"pr_main_color": "#17202A",
						"pr_grad_color": "#17202A",
						"border_width": 0,
						"border_color": "#0B1928",
						"radius": 0,
						"color": "#FFFFFF",
						"font": "supermarket_30"
					}
				},
				"component-1": {
					"name": "Label",
					"property": {
						"name": "txt1",
						"hidden": 1,
						"alignX": 1,
						"alignY": 0,
						"x": 0,
						"y": 20,
						"width": 0,
						"height": 0,
						"text": "WiFi Scan",
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
						"alignY": 1,
						"x": 0,
						"y": 30,
						"width": 600,
						"height": 300,
						"text": "Scaning...",
						"text_align": 0,
						"color": "#FFFFFF",
						"mode": 1,
						"font": "supermarket_30"
					}
				}
			}
		}
	]
}