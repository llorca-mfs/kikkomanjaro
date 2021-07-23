/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 20, .gappx = 20};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=12:antialias=true:autohint=true", "Baybayin Modern Mono:size=15:antialias=true:autohint=true"};
static const char dmenufont[]       = "JetBrains Mono:size=12:antialias=true:autohint=true";
static const char col_gray1[]       = "#282828";
static const char col_gray2[]       = "#3c3836";
static const char col_gray3[]       = "#ebdbb2";
static const char col_gray4[]       = "#fdf1c7";
static const char col_cyan[]        = "#98971a";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "ᜁᜐ", "ᜇᜎᜏ", "ᜆᜆ᜔ᜎᜓ", "ᜀᜉᜆ᜔", "ᜎᜒᜋ", "ᜀᜈᜒᜋ᜔", "ᜉᜒᜆᜓ", "ᜏᜎᜓ", "ᜐᜒᜌᜋ᜔" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *upvol[]   = { "amixer", "set", "Master", "1%+",     NULL };
static const char *downvol[] = { "amixer", "set", "Master", "1%-",     NULL };

static Key keys[] = {
	/* modifier             key    function        argument */
	{ MODKEY,               41,    spawn,          {.v = dmenucmd } }, // f
	{ MODKEY,     28,    spawn,          {.v = termcmd } }, // t
	{ MODKEY,               32,      spawn,      SHCMD("pacmd set-default-sink 0") },
	{ MODKEY,               33,      spawn,      SHCMD("pacmd set-default-sink 1") },
	{ MODKEY,               26,    focusstack,     {.i = +1 } },      // e
	{ MODKEY,               24,    focusstack,     {.i = -1 } },      // q
	{ MODKEY,               25,    incnmaster,     {.i = +1 } },      // w
	{ MODKEY,               39,    incnmaster,     {.i = -1 } },      // s
	{ MODKEY,               38,    setmfact,       {.f = -0.05} },    // a
	{ MODKEY,               40,    setmfact,       {.f = +0.05} },    // d
	{ MODKEY,               36,    zoom,           {0} },             // Return
	{ MODKEY,               23,    view,           {0} },             // Tab
	{ MODKEY,               53,    killclient,     {0} },             // c
	{ MODKEY,               56,    setlayout,      {.v = &layouts[0]} }, // b
	{ MODKEY,               57,    setlayout,      {.v = &layouts[1]} }, // n
	{ MODKEY,               58,    setlayout,      {.v = &layouts[2]} }, // m
	{ MODKEY,               65,    setlayout,      {0} },             // space
	{ MODKEY|ShiftMask,     65,    togglefloating, {0} },             // space
	{ MODKEY,               19,    view,           {.ui = ~0 } },     // 0
	{ MODKEY|ShiftMask,     19,    tag,            {.ui = ~0 } },     // 0
	{ MODKEY,               59,    focusmon,       {.i = -1 } },      // comma
	{ MODKEY,               60,    focusmon,       {.i = +1 } },      // period
	{ MODKEY|ShiftMask,     59,    tagmon,         {.i = -1 } },      // comma
	{ MODKEY|ShiftMask,     60,    tagmon,         {.i = +1 } },      // period
	{ MODKEY,                       20,  setgaps,        {.i = -5 } },
	{ MODKEY,                       21,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             20,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             21,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                10,                    0)                 // 1
	TAGKEYS(                11,                    1)                 // 2
	TAGKEYS(                12,                    2)                 // 3
	TAGKEYS(                13,                    3)                 // 4
	TAGKEYS(                14,                    4)                 // 5
	TAGKEYS(                15,                    5)                 // 6
	TAGKEYS(                16,                    6)                 // 7
	TAGKEYS(                17,                    7)                 // 8
	TAGKEYS(                18,                    8)                 // 9
	{ 0,                       122, spawn, {.v = downvol } },
	{ 0,                       123, spawn, {.v = upvol   } },
	{ 0,                       107,      spawn,      SHCMD("maim -s | xclip -selection clipboard -t image/png") },
	{ MODKEY,                  107,      spawn,      SHCMD("maim -s ~/Pictures/$(date +maim-%m%d%Y-%I%M%S).png | xclip -selection") },
	{ MODKEY|ShiftMask,     24,    quit,           {0} },             // x
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

