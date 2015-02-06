#pragma once

#include "ofMain.h"
#include "labels.h"
#include "data.h"
#include "ui.h"

#define NUM_ROUTES 111

//TODO
// display day
// scroll away day
// day menu
// time of day slider (top left)
// trips back
// swipe to see back trips
// go to current time
//i know this is awful...

class ofApp : public ofBaseApp {
    int secondsInAWeek = 24*60*60*7;

    struct centerOfView ball;
    struct mouseToss toss;
    struct currentTimeCursor nowCursor;

    long lastClickTime;
    bool drawReturn = false;

public:

    int heightOfWeek = ofGetHeight()*32;
    int heightOfDay = heightOfWeek/7;
    int beginningSecond;
    int endingSecond;

    int viewTranslateY;
    ofTrueTypeFont hourLabelFont;
    ofTrueTypeFont fromLocationFont;
    ofTrueTypeFont fromTimeFont;
    ofTrueTypeFont fromTimeAMPMFont;

    ofTrueTypeFont toLocationFont;
    ofTrueTypeFont toTimeFont;
    ofTrueTypeFont toTimeAMPMFont;

    ofTrueTypeFont dayLabelFont;

    struct dayLabel mondayLabel = dayLabel(0, heightOfDay);
    struct dayLabel tuesdayLabel = dayLabel(1, heightOfDay);
    struct dayLabel wednesdayLabel = dayLabel(2, heightOfDay);
    struct dayLabel thursdayLabel = dayLabel(3, heightOfDay);
    struct dayLabel fridayLabel = dayLabel(4, heightOfDay);
    struct dayLabel saturdayLabel = dayLabel(5, heightOfDay);
    struct dayLabel sundayLabel = dayLabel(6, heightOfDay);

    void setup();
    void update();
    void draw();

    void drawDayGrid(int r, int g, int b, int brightnessDiff);
    void drawHellertownToPABT();
    void drawPABTtoHellertown();
    inline void snapToCurrentTime() {
        ball.target.y = ofMap(nowCursor.secIntoWeek - (42*60), 0, secondsInAWeek, ofGetHeight(), 0);
    }

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDoubleClicked();
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);


    tripTime toPABT[NUM_ROUTES] = {
        {busTime(15900),busTime(21600)},
        {busTime(17100),busTime(23700)},
        {busTime(18300),busTime(24900)},
        {busTime(20400),busTime(27600)},
        {busTime(21600),busTime(29100)},
        {busTime(22800),busTime(29400)},
        {busTime(24600),busTime(31200)},
        {busTime(26400),busTime(33000)},
        {busTime(28200),busTime(34800)},
        {busTime(30000),busTime(36600)},
        {busTime(33600),busTime(40200)},
        {busTime(34500),busTime(41100)},
        {busTime(37200),busTime(43800)},
        {busTime(44400),busTime(51300)},
        {busTime(48000),busTime(54900)},
        {busTime(53400),busTime(60000)},
        {busTime(62400),busTime(68400)},
        {busTime(67800),busTime(73800)},
        {busTime(75000),busTime(81000)},
        {busTime(102300),busTime(108000)},
        {busTime(103500),busTime(110100)},
        {busTime(104700),busTime(111300)},
        {busTime(106800),busTime(114000)},
        {busTime(108000),busTime(115500)},
        {busTime(109200),busTime(115800)},
        {busTime(111000),busTime(117600)},
        {busTime(112800),busTime(119400)},
        {busTime(114600),busTime(121200)},
        {busTime(116400),busTime(123000)},
        {busTime(120000),busTime(126600)},
        {busTime(120900),busTime(127500)},
        {busTime(123600),busTime(130200)},
        {busTime(130800),busTime(137700)},
        {busTime(134400),busTime(141300)},
        {busTime(139800),busTime(146400)},
        {busTime(148800),busTime(154800)},
        {busTime(154200),busTime(160200)},
        {busTime(161400),busTime(167400)},
        {busTime(188700),busTime(194400)},
        {busTime(189900),busTime(196500)},
        {busTime(191100),busTime(197700)},
        {busTime(193200),busTime(200400)},
        {busTime(194400),busTime(201900)},
        {busTime(195600),busTime(202200)},
        {busTime(197400),busTime(204000)},
        {busTime(199200),busTime(205800)},
        {busTime(201000),busTime(207600)},
        {busTime(202800),busTime(209400)},
        {busTime(206400),busTime(213000)},
        {busTime(207300),busTime(213900)},
        {busTime(210000),busTime(216600)},
        {busTime(217200),busTime(224100)},
        {busTime(220800),busTime(227700)},
        {busTime(226200),busTime(232800)},
        {busTime(235200),busTime(241200)},
        {busTime(240600),busTime(246600)},
        {busTime(247800),busTime(253800)},
        {busTime(275100),busTime(280800)},
        {busTime(276300),busTime(282900)},
        {busTime(277500),busTime(284100)},
        {busTime(279600),busTime(286800)},
        {busTime(280800),busTime(288300)},
        {busTime(282000),busTime(288600)},
        {busTime(283800),busTime(290400)},
        {busTime(285600),busTime(292200)},
        {busTime(287400),busTime(294000)},
        {busTime(289200),busTime(295800)},
        {busTime(292800),busTime(299400)},
        {busTime(293700),busTime(300300)},
        {busTime(296400),busTime(303000)},
        {busTime(303600),busTime(310500)},
        {busTime(307200),busTime(314100)},
        {busTime(312600),busTime(319200)},
        {busTime(321600),busTime(327600)},
        {busTime(327000),busTime(333000)},
        {busTime(334200),busTime(340200)},
        {busTime(361500),busTime(367200)},
        {busTime(362700),busTime(369300)},
        {busTime(363900),busTime(370500)},
        {busTime(366000),busTime(373200)},
        {busTime(367200),busTime(374700)},
        {busTime(368400),busTime(375000)},
        {busTime(370200),busTime(376800)},
        {busTime(372000),busTime(378600)},
        {busTime(373800),busTime(380400)},
        {busTime(375600),busTime(382200)},
        {busTime(379200),busTime(385800)},
        {busTime(380100),busTime(386700)},
        {busTime(382800),busTime(389400)},
        {busTime(390000),busTime(396900)},
        {busTime(393600),busTime(400500)},
        {busTime(399000),busTime(405600)},
        {busTime(408000),busTime(414000)},
        {busTime(413400),busTime(419400)},
        {busTime(420600),busTime(426600)},
        {busTime(454500),busTime(460800)},
        {busTime(461700),busTime(468000)},
        {busTime(468900),busTime(475260)},
        {busTime(476100),busTime(482400)},
        {busTime(483300),busTime(489600)},
        {busTime(490500),busTime(496800)},
        {busTime(497700),busTime(504000)},
        {busTime(504900),busTime(511200)},
        {busTime(540900),busTime(547200)},
        {busTime(548100),busTime(554400)},
        {busTime(555300),busTime(561660)},
        {busTime(562500),busTime(568800)},
        {busTime(569700),busTime(576000)},
        {busTime(576900),busTime(583200)},
        {busTime(584100),busTime(590400)},
        {busTime(591300),busTime(597600)}
    };

    tripTime toHellertown[NUM_ROUTES] = {
        {busTime(27000),busTime(33300)},
        {busTime(30600),busTime(36900)},
        {busTime(36000),busTime(42300)},
        {busTime(45000),busTime(51300)},
        {busTime(46800),busTime(53100)},
        {busTime(50400),busTime(56700)},
        {busTime(54000),busTime(60300)},
        {busTime(55800),busTime(62100)},
        {busTime(57600),busTime(63900)},
        {busTime(59400),busTime(65700)},
        {busTime(61200),busTime(67500)},
        {busTime(63000),busTime(69300)},
        {busTime(64800),busTime(71100)},
        {busTime(66000),busTime(72000)},
        {busTime(67800),busTime(73800)},
        {busTime(71100),busTime(77400)},
        {busTime(73800),busTime(80100)},
        {busTime(79200),busTime(85500)},
        {busTime(87300),busTime(93600)},
        {busTime(113400),busTime(119700)},
        {busTime(117000),busTime(123300)},
        {busTime(122400),busTime(128700)},
        {busTime(131400),busTime(137700)},
        {busTime(133200),busTime(139500)},
        {busTime(136800),busTime(143100)},
        {busTime(140400),busTime(146700)},
        {busTime(142200),busTime(148500)},
        {busTime(144000),busTime(150300)},
        {busTime(145800),busTime(152100)},
        {busTime(147600),busTime(153900)},
        {busTime(149400),busTime(155700)},
        {busTime(151200),busTime(157500)},
        {busTime(152400),busTime(158400)},
        {busTime(154200),busTime(160200)},
        {busTime(157500),busTime(163800)},
        {busTime(160200),busTime(166500)},
        {busTime(165600),busTime(171900)},
        {busTime(173700),busTime(180000)},
        {busTime(199800),busTime(206100)},
        {busTime(203400),busTime(209700)},
        {busTime(208800),busTime(215100)},
        {busTime(217800),busTime(224100)},
        {busTime(219600),busTime(225900)},
        {busTime(223200),busTime(229500)},
        {busTime(226800),busTime(233100)},
        {busTime(228600),busTime(234900)},
        {busTime(230400),busTime(236700)},
        {busTime(232200),busTime(238500)},
        {busTime(234000),busTime(240300)},
        {busTime(235800),busTime(242100)},
        {busTime(237600),busTime(243900)},
        {busTime(238800),busTime(244800)},
        {busTime(240600),busTime(246600)},
        {busTime(243900),busTime(250200)},
        {busTime(246600),busTime(252900)},
        {busTime(252000),busTime(258300)},
        {busTime(260100),busTime(266400)},
        {busTime(286200),busTime(292500)},
        {busTime(289800),busTime(296100)},
        {busTime(295200),busTime(301500)},
        {busTime(304200),busTime(310500)},
        {busTime(306000),busTime(312300)},
        {busTime(309600),busTime(315900)},
        {busTime(313200),busTime(319500)},
        {busTime(315000),busTime(321300)},
        {busTime(316800),busTime(323100)},
        {busTime(318600),busTime(324900)},
        {busTime(320400),busTime(326700)},
        {busTime(322200),busTime(328500)},
        {busTime(324000),busTime(330300)},
        {busTime(325200),busTime(331200)},
        {busTime(327000),busTime(333000)},
        {busTime(330300),busTime(336600)},
        {busTime(333000),busTime(339300)},
        {busTime(338400),busTime(344700)},
        {busTime(346500),busTime(352800)},
        {busTime(372600),busTime(378900)},
        {busTime(376200),busTime(382500)},
        {busTime(381600),busTime(387900)},
        {busTime(390600),busTime(396900)},
        {busTime(392400),busTime(398700)},
        {busTime(396000),busTime(402300)},
        {busTime(399600),busTime(405900)},
        {busTime(401400),busTime(407700)},
        {busTime(403200),busTime(409500)},
        {busTime(405000),busTime(411300)},
        {busTime(406800),busTime(413100)},
        {busTime(408600),busTime(414900)},
        {busTime(410400),busTime(416700)},
        {busTime(411600),busTime(417600)},
        {busTime(413400),busTime(419400)},
        {busTime(416700),busTime(423000)},
        {busTime(419400),busTime(425700)},
        {busTime(424800),busTime(431100)},
        {busTime(432900),busTime(439200)},
        {busTime(464400),busTime(470700)},
        {busTime(471600),busTime(477900)},
        {busTime(478800),busTime(485100)},
        {busTime(486000),busTime(492300)},
        {busTime(493200),busTime(499500)},
        {busTime(500400),busTime(506700)},
        {busTime(507600),busTime(513900)},
        {busTime(518340),busTime(524700)},
        {busTime(550800),busTime(557100)},
        {busTime(558000),busTime(564300)},
        {busTime(565200),busTime(571500)},
        {busTime(572400),busTime(578700)},
        {busTime(579600),busTime(585900)},
        {busTime(586800),busTime(593100)},
        {busTime(594000),busTime(600300)},
        {busTime(604740),busTime(611100)}};
};
