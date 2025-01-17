//
// This file contains chip-profiles which allow us to adjust
// certain settings that varied wildly between 6581 chips, even
// made in the same factory on the same day.
//
// This works under the assumption that the authors used the
// same SID chip their entire career.
//
{ "20th Century Composers",				{	.folder = "/MUSICIANS/0-9/20CC/",					.fltCox = 0.4	} },
{ "Anthony Lees",						{	.folder = "/MUSICIANS/L/Lees_Anthony/",				.fltCox = 1.3	} },
{ "Antony Crowther (Ratt)",				{	.folder = "/MUSICIANS/C/Crowther_Antony/",			.fltCox = 1.1,	} },
{ "Barry Leitch (The Jackal)",			{	.folder = "/MUSICIANS/L/Leitch_Barry/",				.fltCox = 0.3	} },
{ "Ben Daglish",						{	.folder = "/MUSICIANS/D/Daglish_Ben/",				.fltCox = 0.6,	.exceptions = { { "Last_Ninja", "Anthony Lees" } } } },	// Only Anthony Lees used the filter
{ "Carsten Berggreen (Scarzix)",		{	.folder = "/MUSICIANS/S/Scarzix/",					.fltCox = 0.7	} },
{ "Charles Deenen",						{	.folder = "/MUSICIANS/D/Deenen_Charles/",			.fltCox = 0.2	} },
{ "Chris Hülsbeck",						{	.folder = "/MUSICIANS/H/Huelsbeck_Chris/",			.fltCox = 0.9,	.flt0Dac = 0.2	} },
{ "Clever Music",						{	.folder = "/MUSICIANS/C/Clever_Music/",				.fltCox = 0.25	} },
{ "David Dunn",							{	.folder = "/MUSICIANS/D/Dunn_David/",				.fltCox = 0.015,.flt0Dac = 1.5,	.digi = 0.8	 } },
{ "David Whittaker",					{	.folder = "/MUSICIANS/W/Whittaker_David/",			.fltCox = 0.05,	.flt0Dac = 1.2 } },
{ "Edwin van Santen",					{	.folder = "/MUSICIANS/0-9/20CC/van_Santen_Edwin/",	.fltCox = 0.3	} },
{ "Falco Paul",							{	.folder = "/MUSICIANS/0-9/20CC/Paul_Falco/",		.fltCox = 0.15	} },
{ "Figge Wasberger (Fegolhuzz)",		{	.folder = "/MUSICIANS/F/Fegolhuzz/",				.fltCox = 0.25	} },
{ "Fred Gray",							{	.folder = "/MUSICIANS/G/Gray_Fred/",				.fltCox = 0.8,	.flt0Dac = 1.5, .fltGain = 1.5	} },
{ "Geir Tjelta",						{	.folder = "/MUSICIANS/T/Tjelta_Geir/",				.fltCox = 0.5	} },
{ "Georg Feil",							{	.folder = "/MUSICIANS/F/Feil_Georg/",				.fltCox = 0.2	} },
{ "Glenn Gallefoos",					{	.folder = "/MUSICIANS/B/Blues_Muz/Gallefoss_Glenn/",.fltCox = 1.3,	.flt0Dac = 0.5,	.fltGain = 0.85	} },
{ "Jason C. Brooke",					{	.folder = "/MUSICIANS/B/Brooke_Jason/",				.fltCox = 0.1,	.flt0Dac = 0.8 } },
{ "Jason Page",							{	.folder = "/MUSICIANS/P/Page_Jason/",				.fltCox = 0.35	} },
{ "Jeroen Tel",							{	.folder = "/MUSICIANS/T/Tel_Jeroen/",				.fltCox = 0.35,	.fltGain = 0.85,	.exceptions = { { "Outrun_Europa", "Jeroen Tel (Outrun Europa)" } } } },
{ "Jeroen Tel (Outrun Europa)",			{	.folder = "/MUSICIANS/T/Tel_Jeroen_2/",				.fltCox = 0.35,	.fltGain = 0.85,	.digi = 0.55 } },
{ "Johannes Bjerregaard",				{	.folder = "/MUSICIANS/B/Bjerregaard_Johannes/",		.fltCox = 0.35, .exceptions = { { "Stormlord", "Jeroen Tel"	} } } },
{ "Jonathan Dunn",						{	.folder = "/MUSICIANS/D/Dunn_Jonathan/",			.fltCox = 0.4,	.fltGain = 0.8	} },
{ "Jori Olkkonen (Yip)",				{	.folder = "/MUSICIANS/Y/Yip/",						.fltCox = 0.35,	.flt0Dac = 0.6	} },
{ "Jouni Ikonen (Mixer)",				{	.folder = "/MUSICIANS/M/Mixer/",					.fltCox = 0.5,	.fltGain = 0.85	} },
{ "Kim Christensen (Future Freak)",		{	.folder = "/MUSICIANS/F/Future_Freak/",				.fltCox = 0.35	} },
{ "Laxity",								{	.folder = "/MUSICIANS/L/Laxity/",					.fltCox = 0.3	} },
{ "Linus Åkesson (lft)",				{	.folder = "/MUSICIANS/L/Lft/",						.fltCox = 0.3	} },
{ "Mark Cooksey",						{	.folder = "/MUSICIANS/C/Cooksey_Mark/",				.fltCox = 0.4,	.flt0Dac = 0.7	} },
{ "Mark Wilson",						{	.folder = "/MUSICIANS/W/Wilson_Mark/",				.fltCox = 0.2	} },
{ "Markus Klein (LMan)",				{	.folder = "/MUSICIANS/L/LMan/",						.fltCox = 0.4,	.fltGain = 0.7	} },
{ "Markus Müller",						{	.folder = "/MUSICIANS/M/Mueller_Markus/",			.fltCox = 0.5,	.flt0Dac = 0.3	} },
{ "Martin Galway",						{	.folder = "/MUSICIANS/G/Galway_Martin/",			.fltCox = 0.65,	.flt0Dac = 0.6 } },
{ "Martin Walker",						{	.folder = "/MUSICIANS/W/Walker_Martin/",			.fltCox = 0.15	} },
{ "Matt Gray",							{	.folder = "/MUSICIANS/G/Gray_Matt/",				.fltCox = 0.3,	.fltGain = 1.0,	.digi = 0.8	} },
{ "Michael Hendriks",					{	.folder = "/MUSICIANS/F/FAME/Hendriks_Michael/",	.fltCox = 0.35,	.flt0Dac = 0.7,	.digi = 0.3		} },
{ "Michael Nilsson-Vonderburgh (Mitch)",{	.folder = "/MUSICIANS/M/Mitch_and_Dane/Mitch/",		.fltCox = 0.3,	.flt0Dac = 0.2	} },
{ "Mitch & Dane",						{	.folder = "/MUSICIANS/M/Mitch_and_Dane/",			.fltCox = 0.85,	.flt0Dac = 0.3,	.cwsThreshold = 0.5	} },
{ "Neil Brennan",						{	.folder = "/MUSICIANS/B/Brennan_Neil/",				.fltCox = 0.25	} },
{ "Nigel Grieve",						{	.folder = "/MUSICIANS/G/Grieve_Nigel/",				.fltCox = 1.0,	.fltGain = 1.5	} },
{ "Paul Hannay (Feekzoid)",				{	.folder = "/MUSICIANS/F/Feekzoid/",			} },
{ "Peter Clarke",						{	.folder = "/MUSICIANS/C/Clarke_Peter/",				.fltCox = 0.2	} },
{ "Pex Tufvesson",						{	.folder = "/MUSICIANS/M/Mahoney/",					.fltCox = 0.35	} },
{ "Ramiro Vaca",						{	.folder = "/MUSICIANS/V/Vaca_Ramiro/",				.fltCox = 0.7,	} },
{ "Reyn Ouwehand",						{	.folder = "/MUSICIANS/O/Ouwehand_Reyn/",			.fltCox = 0.8,	.flt0Dac = 0.2	} },
{ "Richard Joseph",						{	.folder = "/MUSICIANS/J/Joseph_Richard/",			.fltCox = 0.3	} },
{ "Rob Hubbard",						{	.folder = "/MUSICIANS/H/Hubbard_Rob/",				.fltCox = 0.35,	.flt0Dac = 0.6,	.fltGain = 0.8,	.digi = 0.9	} },
{ "Russell Lieblich",					{	.folder = "/MUSICIANS/L/Lieblich_Russell/",			.fltCox = 0.25,	.flt0Dac = 0.7	} },
{ "Shaun Southern",						{	.folder = "/MUSICIANS/S/Southern_Shaun/",			.fltCox = 0.1,	.flt0Dac = 0.9	} },
{ "Stellan Andersson (Dane)",			{	.folder = "/MUSICIANS/M/Mitch_and_Dane/Dane/",		.fltCox = 0.85,	.flt0Dac = 0.3	} },
{ "Steve Barrett",						{	.folder = "/MUSICIANS/B/Barrett_Steve/",			.digi = 0.55 } },
{ "Steve Turner",						{	.folder = "/MUSICIANS/T/Turner_Steve/",				.fltCox = 0.6,	.exceptions = { { "Bushido", "Jason Page"	} } } },	// Only Jason Page used the filter for subtune 2
{ "Thomas Mogensen (DRAX)",				{	.folder = "/MUSICIANS/D/DRAX/",						.fltCox = 0.3	} },
{ "Tim Follin",							{	.folder = "/MUSICIANS/F/Follin_Tim/",				.fltCox = 0.7	} },
{ "Geoff Follin",						{	.folder = "/MUSICIANS/F/Follin_Geoff/",				.fltCox = 0.7	} },
{ "Zoci-Joe",							{	.folder = "/MUSICIANS/Z/Zoci-Joe/",					.fltCox = 0.3	} },
{ "Matthew Cannon",						{	.folder = "/MUSICIANS/C/Cannon_Matthew/",			.fltCox = 0.4,	.fltGain = 0.8	} },
{ "Keith Tinman",						{	.folder = "/MUSICIANS/T/Tinman_Keith/",				.fltCox = 0.4,	.fltGain = 0.7	} },
{ "Gerard Gourley",						{	.folder = "/MUSICIANS/S/Sonic_Graffiti/Gourley_Gerard/",	.fltCox = 0.1,	.flt0Dac = 1.5,	.fltGain = 0.8	} },
{ "Frederik Segerfalk",					{	.folder = "/MUSICIANS/M/Moppe/",					.fltCox = 0.9	} },
{ "David Sturgeon (Abynx)",				{	.folder = "/MUSICIANS/A/Abynx/",					.fltCox = 0.1,	.flt0Dac = 0.3,	.fltGain = 0.8	} },
