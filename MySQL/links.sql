/*
 Navicat Premium Data Transfer

 Source Server         : mysql
 Source Server Type    : MySQL
 Source Server Version : 80011
 Source Host           : 35.194.137.178:3306
 Source Schema         : subway

 Target Server Type    : MySQL
 Target Server Version : 80011
 File Encoding         : 65001

 Date: 04/12/2018 19:10:24
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for links
-- ----------------------------
DROP TABLE IF EXISTS `links`;
CREATE TABLE `links`  (
  `source` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `target` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `line` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `value` decimal(6, 4) NOT NULL,
  `pinyinsource` char(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`source`, `target`, `line`) USING BTREE,
  INDEX `target`(`target`) USING BTREE,
  INDEX `line`(`line`) USING BTREE,
  CONSTRAINT `links_ibfk_1` FOREIGN KEY (`source`) REFERENCES `nodes` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `links_ibfk_2` FOREIGN KEY (`target`) REFERENCES `nodes` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `links_ibfk_3` FOREIGN KEY (`line`) REFERENCES `nodes` (`group`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of links
-- ----------------------------
INSERT INTO `links` VALUES ('七里庄', '丰台东大街', '九号线', 1.3250, NULL);
INSERT INTO `links` VALUES ('七里庄', '西局', '十三号线', 0.8450, NULL);
INSERT INTO `links` VALUES ('七里庄', '西局', '十四号西段', 0.8450, NULL);
INSERT INTO `links` VALUES ('万寿路', '公主坟', '一号线', 1.3130, NULL);
INSERT INTO `links` VALUES ('万源街', '荣京东街', '亦庄线', 1.0900, NULL);
INSERT INTO `links` VALUES ('三元桥', '亮马桥', '十号线', 1.5060, NULL);
INSERT INTO `links` VALUES ('上地', '西二旗', '十三号线', 2.5380, NULL);
INSERT INTO `links` VALUES ('东单', '崇文门', '五号线', 0.8210, NULL);
INSERT INTO `links` VALUES ('东单', '建国门', '一号线', 1.2300, NULL);
INSERT INTO `links` VALUES ('东四', '朝阳门', '六号线', 1.3990, NULL);
INSERT INTO `links` VALUES ('东四', '灯市口', '五号线', 0.8480, NULL);
INSERT INTO `links` VALUES ('东四十条', '东直门', '二号线', 0.8240, NULL);
INSERT INTO `links` VALUES ('东夏园', '潞城', '六号线', 1.1940, NULL);
INSERT INTO `links` VALUES ('东大桥', '呼家楼', '六号线', 0.8450, NULL);
INSERT INTO `links` VALUES ('东湖渠', '来广营', '十四号东段', 1.1000, NULL);
INSERT INTO `links` VALUES ('东直门', '雍和宫', '二号线', 2.2280, NULL);
INSERT INTO `links` VALUES ('东风北桥', '将台', '十四号东段', 1.6000, NULL);
INSERT INTO `links` VALUES ('中关村', '海淀黄庄', '四号线', 0.9000, NULL);
INSERT INTO `links` VALUES ('丰台东大街', '丰台南路', '九号线', 1.5850, NULL);
INSERT INTO `links` VALUES ('丰台南路', '科怡路', '九号线', 0.9800, NULL);
INSERT INTO `links` VALUES ('丰台科技园', '郭公庄', '九号线', 1.3470, NULL);
INSERT INTO `links` VALUES ('丰台站', '泥洼', '十号线', 0.9540, NULL);
INSERT INTO `links` VALUES ('临河里', '土桥', '八通线', 0.7760, NULL);
INSERT INTO `links` VALUES ('义和庄', '生物医药基地', '大兴线', 2.9180, NULL);
INSERT INTO `links` VALUES ('九棵树', '梨园', '八通线', 1.2250, NULL);
INSERT INTO `links` VALUES ('九龙山', '大望路', '十四号东段', 1.7800, NULL);
INSERT INTO `links` VALUES ('九龙山', '大郊亭', '七号线', 0.7810, NULL);
INSERT INTO `links` VALUES ('五棵松', '万寿路', '一号线', 1.7780, NULL);
INSERT INTO `links` VALUES ('五道口', '上地', '十三号线', 4.8660, NULL);
INSERT INTO `links` VALUES ('亦庄文化园', '万源街', '亦庄线', 1.7280, NULL);
INSERT INTO `links` VALUES ('亦庄桥', '亦庄文化园', '亦庄线', 0.9930, NULL);
INSERT INTO `links` VALUES ('亮马桥', '农业展览馆', '十号线', 0.9140, NULL);
INSERT INTO `links` VALUES ('人民大学', '魏公村', '四号线', 1.0510, NULL);
INSERT INTO `links` VALUES ('什刹海', '南锣鼓巷', '八号线', 0.9020, NULL);
INSERT INTO `links` VALUES ('传媒大学', '双桥', '八通线', 1.8940, NULL);
INSERT INTO `links` VALUES ('健德门', '北土城', '十号线', 1.1000, NULL);
INSERT INTO `links` VALUES ('光熙门', '柳芳', '十三号线', 1.1350, NULL);
INSERT INTO `links` VALUES ('八宝山', '玉泉路', '一号线', 1.4790, NULL);
INSERT INTO `links` VALUES ('八角游乐园', '八宝山', '一号线', 1.9530, NULL);
INSERT INTO `links` VALUES ('八里桥', '通州北苑', '八通线', 1.7000, NULL);
INSERT INTO `links` VALUES ('公主坟', '军事博物馆', '一号线', 1.1720, NULL);
INSERT INTO `links` VALUES ('公主坟', '西钓鱼台', '十号线', 2.3860, NULL);
INSERT INTO `links` VALUES ('公益西桥', '新宫', '大兴线', 2.7980, NULL);
INSERT INTO `links` VALUES ('六道口', '北沙滩', '十五号', 1.3370, NULL);
INSERT INTO `links` VALUES ('六里桥', '七里庄', '九号线', 1.7780, NULL);
INSERT INTO `links` VALUES ('六里桥', '莲花桥', '十号线', 2.3920, NULL);
INSERT INTO `links` VALUES ('六里桥东', '六里桥', '九号线', 1.3090, NULL);
INSERT INTO `links` VALUES ('关庄', '望京西', '十五号', 2.0710, NULL);
INSERT INTO `links` VALUES ('军事博物馆', '北京西站', '九号线', 1.3980, NULL);
INSERT INTO `links` VALUES ('军事博物馆', '木樨地', '一号线', 1.1660, NULL);
INSERT INTO `links` VALUES ('农业展览馆', '团结湖', '十号线', 0.8530, NULL);
INSERT INTO `links` VALUES ('分钟寺', '成寿寺', '十号线', 1.0580, NULL);
INSERT INTO `links` VALUES ('刘家窑', '宋家庄', '五号线', 1.6700, NULL);
INSERT INTO `links` VALUES ('前门', '崇文门', '二号线', 1.6340, NULL);
INSERT INTO `links` VALUES ('动物园', '西直门', '四号线', 1.4410, NULL);
INSERT INTO `links` VALUES ('劲松', '潘家园', '十号线', 1.0210, NULL);
INSERT INTO `links` VALUES ('化工', '南楼梓庄', '七号线', 1.4640, NULL);
INSERT INTO `links` VALUES ('北京南站', '陶然桥', '十四号东段', 0.8870, NULL);
INSERT INTO `links` VALUES ('北京南站', '马家堡', '四号线', 1.4800, NULL);
INSERT INTO `links` VALUES ('北京大学东门', '中关村', '四号线', 0.8870, NULL);
INSERT INTO `links` VALUES ('北京站', '建国门', '二号线', 0.9450, NULL);
INSERT INTO `links` VALUES ('北京西站', '六里桥东', '九号线', 1.1700, NULL);
INSERT INTO `links` VALUES ('北京西站', '湾子', '七号线', 0.9350, NULL);
INSERT INTO `links` VALUES ('北土城', '安华桥', '八号线', 1.0180, NULL);
INSERT INTO `links` VALUES ('北土城', '安贞门', '十号线', 1.0200, NULL);
INSERT INTO `links` VALUES ('北宫门', '西苑', '四号线', 1.2510, NULL);
INSERT INTO `links` VALUES ('北工大西门', '平乐园', '十四号东段', 1.1280, NULL);
INSERT INTO `links` VALUES ('北新桥', '张自忠路', '五号线', 0.7910, NULL);
INSERT INTO `links` VALUES ('北沙滩', '奥林匹克公园', '十五号', 1.9990, NULL);
INSERT INTO `links` VALUES ('北海北', '南锣鼓巷', '六号线', 1.3490, NULL);
INSERT INTO `links` VALUES ('北苑', '望京西', '十三号线', 6.7200, NULL);
INSERT INTO `links` VALUES ('北苑路北', '大屯路东', '五号线', 3.0000, NULL);
INSERT INTO `links` VALUES ('北运河东', '郝家府', '六号线', 0.9290, NULL);
INSERT INTO `links` VALUES ('北运河西', '北运河东', '六号线', 1.5990, NULL);
INSERT INTO `links` VALUES ('北邵洼', '南邵', '昌平线', 1.9580, NULL);
INSERT INTO `links` VALUES ('十三陵景区', '昌平', '昌平线', 3.5080, NULL);
INSERT INTO `links` VALUES ('十里堡', '青年路', '六号线', 1.2820, NULL);
INSERT INTO `links` VALUES ('十里河', '分钟寺', '十号线', 1.8040, NULL);
INSERT INTO `links` VALUES ('十里河', '南八里庄', '十四号东段', 1.1470, NULL);
INSERT INTO `links` VALUES ('南八里庄', '北工大西门', '十四号东段', 1.2760, NULL);
INSERT INTO `links` VALUES ('南楼梓庄', '欢乐谷景区', '七号线', 0.9060, NULL);
INSERT INTO `links` VALUES ('南法信', '石门', '十五号', 2.7120, NULL);
INSERT INTO `links` VALUES ('南礼士路', '复兴门', '一号线', 0.4240, NULL);
INSERT INTO `links` VALUES ('南邵', '沙河高教园', '昌平线', 5.3570, NULL);
INSERT INTO `links` VALUES ('南锣鼓巷', '东四', '六号线', 1.9370, NULL);
INSERT INTO `links` VALUES ('双井', '九龙山', '七号线', 1.3110, NULL);
INSERT INTO `links` VALUES ('双井', '劲松', '十号线', 1.0060, NULL);
INSERT INTO `links` VALUES ('双合', '焦化厂', '七号线', 1.0210, NULL);
INSERT INTO `links` VALUES ('双桥', '管庄', '八通线', 1.9120, NULL);
INSERT INTO `links` VALUES ('古城', '八角游乐园', '一号线', 1.9210, NULL);
INSERT INTO `links` VALUES ('同济南路', '经海路', '亦庄线', 2.3010, NULL);
INSERT INTO `links` VALUES ('后沙峪', '南法信', '十五号', 4.5760, NULL);
INSERT INTO `links` VALUES ('呼家楼', '金台夕照', '十号线', 0.7340, NULL);
INSERT INTO `links` VALUES ('呼家楼', '金台路', '六号线', 1.4500, NULL);
INSERT INTO `links` VALUES ('和平西桥', '和平里北街', '五号线', 1.0590, NULL);
INSERT INTO `links` VALUES ('和平里北街', '雍和宫', '五号线', 1.1510, NULL);
INSERT INTO `links` VALUES ('和平门', '前门', '二号线', 1.1710, NULL);
INSERT INTO `links` VALUES ('四惠', '四惠东', '一号线', 1.7140, NULL);
INSERT INTO `links` VALUES ('四惠', '四惠东', '八通线', 1.7150, NULL);
INSERT INTO `links` VALUES ('四惠东', '高碑店', '八通线', 1.3750, NULL);
INSERT INTO `links` VALUES ('回龙观', '霍营', '十三号线', 2.1100, NULL);
INSERT INTO `links` VALUES ('回龙观东大街', '霍营', '八号线', 1.1140, NULL);
INSERT INTO `links` VALUES ('团结湖', '呼家楼', '十号线', 1.1490, NULL);
INSERT INTO `links` VALUES ('园博园', '大瓦窑', '十三号线', 4.0730, NULL);
INSERT INTO `links` VALUES ('园博园', '大瓦窑', '十四号西段', 4.0730, NULL);
INSERT INTO `links` VALUES ('国家图书馆', '动物园', '四号线', 1.5170, NULL);
INSERT INTO `links` VALUES ('国家图书馆', '白石桥南', '九号线', 1.0960, NULL);
INSERT INTO `links` VALUES ('国展', '花梨坎', '十五号', 1.6150, NULL);
INSERT INTO `links` VALUES ('国贸', '双井', '十号线', 1.7590, NULL);
INSERT INTO `links` VALUES ('国贸', '大望路', '一号线', 1.3850, NULL);
INSERT INTO `links` VALUES ('圆明园', '北京大学东门', '四号线', 1.2950, NULL);
INSERT INTO `links` VALUES ('垡头', '双合', '七号线', 1.3040, NULL);
INSERT INTO `links` VALUES ('复兴门', '西单', '一号线', 1.5900, NULL);
INSERT INTO `links` VALUES ('复兴门', '长椿街', '二号线', 1.2340, NULL);
INSERT INTO `links` VALUES ('大井', '七里庄', '十三号线', 1.5790, NULL);
INSERT INTO `links` VALUES ('大井', '七里庄', '十四号西段', 1.5790, NULL);
INSERT INTO `links` VALUES ('大屯路东', '关庄', '十五号', 1.0870, NULL);
INSERT INTO `links` VALUES ('大屯路东', '惠新西街北口', '五号线', 1.8380, NULL);
INSERT INTO `links` VALUES ('大望路', '四惠', '一号线', 1.6730, NULL);
INSERT INTO `links` VALUES ('大望路', '红庙', '十四号东段', 0.7080, NULL);
INSERT INTO `links` VALUES ('大瓦窑', '郭庄子', '十三号线', 1.2360, NULL);
INSERT INTO `links` VALUES ('大瓦窑', '郭庄子', '十四号西段', 1.2360, NULL);
INSERT INTO `links` VALUES ('大红门', '角门东', '十号线', 1.1300, NULL);
INSERT INTO `links` VALUES ('大葆台', '稻田', '房山站', 6.4660, NULL);
INSERT INTO `links` VALUES ('大郊亭', '百子湾', '七号线', 0.8650, NULL);
INSERT INTO `links` VALUES ('大钟寺', '知春路', '十三号线', 1.2060, NULL);
INSERT INTO `links` VALUES ('天坛东门', '蒲黄榆', '五号线', 1.9000, NULL);
INSERT INTO `links` VALUES ('天安门东', '王府井', '一号线', 0.8520, NULL);
INSERT INTO `links` VALUES ('天安门西', '天安门东', '一号线', 0.9250, NULL);
INSERT INTO `links` VALUES ('天通苑', '天通苑南', '五号线', 0.9650, NULL);
INSERT INTO `links` VALUES ('天通苑北', '天通苑', '五号线', 0.9390, NULL);
INSERT INTO `links` VALUES ('天通苑南', '立水桥', '五号线', 1.5440, NULL);
INSERT INTO `links` VALUES ('太阳宫', '三元桥', '十号线', 1.7590, NULL);
INSERT INTO `links` VALUES ('奥体中心', '北土城', '八号线', 0.9000, NULL);
INSERT INTO `links` VALUES ('奥林匹克公园', '奥体中心', '八号线', 1.6670, NULL);
INSERT INTO `links` VALUES ('奥林匹克公园', '安立路', '十五号', 1.3680, NULL);
INSERT INTO `links` VALUES ('孙河', '国展', '十五号', 3.3860, NULL);
INSERT INTO `links` VALUES ('安华桥', '安德里北街', '八号线', 1.2740, NULL);
INSERT INTO `links` VALUES ('安定门', '鼓楼大街', '二号线', 1.2370, NULL);
INSERT INTO `links` VALUES ('安德里北街', '鼓楼大街', '八号线', 1.0830, NULL);
INSERT INTO `links` VALUES ('安河桥北', '北宫门', '四号线', 1.3630, NULL);
INSERT INTO `links` VALUES ('安立路', '大屯路东', '十五号', 0.9380, NULL);
INSERT INTO `links` VALUES ('安贞门', '惠新西街南口', '十号线', 0.9820, NULL);
INSERT INTO `links` VALUES ('宋家庄', '石榴庄', '十号线', 1.2690, NULL);
INSERT INTO `links` VALUES ('宋家庄', '肖村', '亦庄线', 2.6310, NULL);
INSERT INTO `links` VALUES ('宣武门', '和平门', '二号线', 0.8510, NULL);
INSERT INTO `links` VALUES ('宣武门', '菜市口', '四号线', 1.1520, NULL);
INSERT INTO `links` VALUES ('将台', '高家园', '十四号东段', 1.1710, NULL);
INSERT INTO `links` VALUES ('小红门', '旧宫', '亦庄线', 2.3660, NULL);
INSERT INTO `links` VALUES ('崇文门', '北京站', '二号线', 1.0230, NULL);
INSERT INTO `links` VALUES ('崇文门', '磁器口', '五号线', 0.8760, NULL);
INSERT INTO `links` VALUES ('崔各庄', '马泉营', '十五号', 2.0080, NULL);
INSERT INTO `links` VALUES ('巩华城', '朱辛庄', '昌平线', 3.7990, NULL);
INSERT INTO `links` VALUES ('巴沟', '苏州街', '十号线', 1.1100, NULL);
INSERT INTO `links` VALUES ('常营', '草房', '六号线', 1.4050, NULL);
INSERT INTO `links` VALUES ('平乐园', '九龙山', '十四号东段', 0.8970, NULL);
INSERT INTO `links` VALUES ('平安里', '北海北', '六号线', 1.3210, NULL);
INSERT INTO `links` VALUES ('平安里', '西四', '四号线', 1.1000, NULL);
INSERT INTO `links` VALUES ('平西府', '回龙观东大街', '八号线', 2.0560, NULL);
INSERT INTO `links` VALUES ('广安门内', '菜市口', '七号线', 1.3740, NULL);
INSERT INTO `links` VALUES ('广渠门内', '广渠门外', '七号线', 1.3320, NULL);
INSERT INTO `links` VALUES ('广渠门外', '双井', '七号线', 1.2410, NULL);
INSERT INTO `links` VALUES ('广阳城', '良乡大学城北', '房山站', 2.0030, NULL);
INSERT INTO `links` VALUES ('建国门', '朝阳门', '二号线', 1.7630, NULL);
INSERT INTO `links` VALUES ('建国门', '永安里', '一号线', 1.3770, NULL);
INSERT INTO `links` VALUES ('张自忠路', '东四', '五号线', 1.0160, NULL);
INSERT INTO `links` VALUES ('张郭庄', '园博园', '十三号线', 1.3450, NULL);
INSERT INTO `links` VALUES ('张郭庄', '园博园', '十四号西段', 1.3450, NULL);
INSERT INTO `links` VALUES ('惠新西街北口', '惠新西街南口', '五号线', 1.1220, NULL);
INSERT INTO `links` VALUES ('惠新西街南口', '和平西桥', '五号线', 1.0250, NULL);
INSERT INTO `links` VALUES ('惠新西街南口', '芍药居', '十号线', 1.7120, NULL);
INSERT INTO `links` VALUES ('慈寿寺', '花园桥', '六号线', 1.4310, NULL);
INSERT INTO `links` VALUES ('慈寿寺', '车道沟', '十号线', 1.5900, NULL);
INSERT INTO `links` VALUES ('成寿寺', '宋家庄', '十号线', 1.6770, NULL);
INSERT INTO `links` VALUES ('新宫', '西红门', '大兴线', 5.1020, NULL);
INSERT INTO `links` VALUES ('新街口', '平安里', '四号线', 1.1000, NULL);
INSERT INTO `links` VALUES ('方庄', '十里河', '十四号东段', 1.6180, NULL);
INSERT INTO `links` VALUES ('旧宫', '亦庄桥', '亦庄线', 1.9820, NULL);
INSERT INTO `links` VALUES ('昌平', '昌平东关', '昌平线', 2.4330, NULL);
INSERT INTO `links` VALUES ('昌平东关', '北邵洼', '昌平线', 1.6830, NULL);
INSERT INTO `links` VALUES ('昌平西山口', '十三陵景区', '昌平线', 1.2130, NULL);
INSERT INTO `links` VALUES ('景泰', '蒲黄榆', '十四号东段', 1.0250, NULL);
INSERT INTO `links` VALUES ('望京', '东湖渠', '十四号东段', 1.2830, NULL);
INSERT INTO `links` VALUES ('望京', '望京东', '十五号', 1.6520, NULL);
INSERT INTO `links` VALUES ('望京东', '崔各庄', '十五号', 2.2950, NULL);
INSERT INTO `links` VALUES ('望京南', '阜通', '十四号东段', 1.1680, NULL);
INSERT INTO `links` VALUES ('望京西', '望京', '十五号', 1.7580, NULL);
INSERT INTO `links` VALUES ('望京西', '芍药居', '十三号线', 2.1520, NULL);
INSERT INTO `links` VALUES ('朝阳公园', '枣营', '十四号东段', 1.2210, NULL);
INSERT INTO `links` VALUES ('朝阳门', '东四十条', '二号线', 1.0270, NULL);
INSERT INTO `links` VALUES ('朝阳门', '东大桥', '六号线', 1.6680, NULL);
INSERT INTO `links` VALUES ('木樨地', '南礼士路', '一号线', 1.2910, NULL);
INSERT INTO `links` VALUES ('朱辛庄', '生命科学园', '昌平线', 2.3670, NULL);
INSERT INTO `links` VALUES ('朱辛庄', '育知路', '八号线', 2.3180, NULL);
INSERT INTO `links` VALUES ('来广营', '善各庄', '十四号东段', 1.3640, NULL);
INSERT INTO `links` VALUES ('林萃桥', '森林公园南门', '八号线', 2.5550, NULL);
INSERT INTO `links` VALUES ('果园', '九棵树', '八通线', 0.9900, NULL);
INSERT INTO `links` VALUES ('枣园', '清源路', '大兴线', 1.2000, NULL);
INSERT INTO `links` VALUES ('枣营', '东风北桥', '十四号东段', 2.1730, NULL);
INSERT INTO `links` VALUES ('柳芳', '东直门', '十三号线', 1.7690, NULL);
INSERT INTO `links` VALUES ('桥湾', '磁器口', '七号线', 1.0160, NULL);
INSERT INTO `links` VALUES ('梨园', '临河里', '八通线', 1.2570, NULL);
INSERT INTO `links` VALUES ('森林公园南门', '奥林匹克公园', '八号线', 1.0160, NULL);
INSERT INTO `links` VALUES ('次渠南', '次渠', '亦庄线', 1.2810, NULL);
INSERT INTO `links` VALUES ('欢乐谷景区', '垡头', '七号线', 1.6790, NULL);
INSERT INTO `links` VALUES ('永安里', '国贸', '一号线', 0.7900, NULL);
INSERT INTO `links` VALUES ('永定门外', '景泰', '十四号东段', 1.1190, NULL);
INSERT INTO `links` VALUES ('永泰庄', '林萃桥', '八号线', 2.5530, NULL);
INSERT INTO `links` VALUES ('沙河', '巩华城', '昌平线', 2.0250, NULL);
INSERT INTO `links` VALUES ('沙河高教园', '沙河', '昌平线', 1.9640, NULL);
INSERT INTO `links` VALUES ('泥洼', '西局', '十号线', 0.7490, NULL);
INSERT INTO `links` VALUES ('海淀五路居', '慈寿寺', '六号线', 1.5080, NULL);
INSERT INTO `links` VALUES ('海淀黄庄', '人民大学', '四号线', 1.0630, NULL);
INSERT INTO `links` VALUES ('海淀黄庄', '知春里', '十号线', 0.9750, NULL);
INSERT INTO `links` VALUES ('清华东路西口', '六道口', '十五号', 1.1440, NULL);
INSERT INTO `links` VALUES ('清源路', '黄村西大街', '大兴线', 1.2140, NULL);
INSERT INTO `links` VALUES ('湾子', '达官营', '七号线', 0.7340, NULL);
INSERT INTO `links` VALUES ('潘家园', '十里河', '十号线', 1.0970, NULL);
INSERT INTO `links` VALUES ('火器营', '巴沟', '十号线', 1.4950, NULL);
INSERT INTO `links` VALUES ('灯市口', '东单', '五号线', 0.9450, NULL);
INSERT INTO `links` VALUES ('灵境胡同', '西单', '四号线', 1.0110, NULL);
INSERT INTO `links` VALUES ('牡丹园', '健德门', '十号线', 0.9730, NULL);
INSERT INTO `links` VALUES ('物资学院路', '通州北关', '六号线', 2.5570, NULL);
INSERT INTO `links` VALUES ('玉泉路', '五棵松', '一号线', 1.8100, NULL);
INSERT INTO `links` VALUES ('王府井', '东单', '一号线', 0.7740, NULL);
INSERT INTO `links` VALUES ('珠市口', '桥湾', '七号线', 0.8690, NULL);
INSERT INTO `links` VALUES ('生命科学园', '西二旗', '昌平线', 5.4400, NULL);
INSERT INTO `links` VALUES ('生物医药基地', '天宫院', '大兴线', 1.8110, NULL);
INSERT INTO `links` VALUES ('白堆子', '军事博物馆', '九号线', 1.9120, NULL);
INSERT INTO `links` VALUES ('白石桥南', '白堆子', '九号线', 0.9430, NULL);
INSERT INTO `links` VALUES ('白石桥南', '车公庄西', '六号线', 1.6640, NULL);
INSERT INTO `links` VALUES ('百子湾', '化工', '七号线', 0.9030, NULL);
INSERT INTO `links` VALUES ('知春路', '五道口', '十三号线', 1.8290, NULL);
INSERT INTO `links` VALUES ('知春路', '西土城', '十号线', 1.1010, NULL);
INSERT INTO `links` VALUES ('知春里', '知春路', '十号线', 1.0580, NULL);
INSERT INTO `links` VALUES ('石榴庄', '大红门', '十号线', 1.2440, NULL);
INSERT INTO `links` VALUES ('石门', '顺义', '十五号', 1.3310, NULL);
INSERT INTO `links` VALUES ('磁器口', '天坛东门', '五号线', 1.1830, NULL);
INSERT INTO `links` VALUES ('磁器口', '广渠门内', '七号线', 1.1380, NULL);
INSERT INTO `links` VALUES ('科怡路', '丰台科技园', '九号线', 0.7880, NULL);
INSERT INTO `links` VALUES ('积水潭', '西直门', '二号线', 1.8990, NULL);
INSERT INTO `links` VALUES ('稻田', '长阳', '房山站', 4.0410, NULL);
INSERT INTO `links` VALUES ('立水桥', '北苑', '十三号线', 2.2720, NULL);
INSERT INTO `links` VALUES ('立水桥', '立水桥南', '五号线', 1.3050, NULL);
INSERT INTO `links` VALUES ('立水桥南', '北苑路北', '五号线', 1.2860, NULL);
INSERT INTO `links` VALUES ('管庄', '八里桥', '八通线', 1.7630, NULL);
INSERT INTO `links` VALUES ('篱笆房', '广阳城', '房山站', 1.4740, NULL);
INSERT INTO `links` VALUES ('红庙', '金台路', '十四号东段', 0.8940, NULL);
INSERT INTO `links` VALUES ('纪家庙', '首经贸', '十号线', 1.1430, NULL);
INSERT INTO `links` VALUES ('经海路', '次渠南', '亦庄线', 2.0550, NULL);
INSERT INTO `links` VALUES ('肖村', '小红门', '亦庄线', 1.2750, NULL);
INSERT INTO `links` VALUES ('育新', '西小口', '八号线', 1.5430, NULL);
INSERT INTO `links` VALUES ('育知路', '平西府', '八号线', 1.9850, NULL);
INSERT INTO `links` VALUES ('良乡南关', '苏庄', '房山站', 1.3300, NULL);
INSERT INTO `links` VALUES ('良乡大学城', '良乡大学城西', '房山站', 1.7380, NULL);
INSERT INTO `links` VALUES ('良乡大学城北', '良乡大学城', '房山站', 1.1880, NULL);
INSERT INTO `links` VALUES ('良乡大学城西', '良乡南关', '房山站', 1.3320, NULL);
INSERT INTO `links` VALUES ('芍药居', '光熙门', '十三号线', 1.1100, NULL);
INSERT INTO `links` VALUES ('芍药居', '太阳宫', '十号线', 1.0030, NULL);
INSERT INTO `links` VALUES ('花园桥', '白石桥南', '六号线', 1.1660, NULL);
INSERT INTO `links` VALUES ('花梨坎', '后沙峪', '十五号', 3.3540, NULL);
INSERT INTO `links` VALUES ('苏州街', '海淀黄庄', '十号线', 0.9500, NULL);
INSERT INTO `links` VALUES ('苹果园', '古城', '一号线', 2.6060, NULL);
INSERT INTO `links` VALUES ('草房', '物资学院路', '六号线', 2.1150, NULL);
INSERT INTO `links` VALUES ('草桥', '纪家庙', '十号线', 1.5470, NULL);
INSERT INTO `links` VALUES ('荣京东街', '荣昌东街', '亦庄线', 1.3550, NULL);
INSERT INTO `links` VALUES ('荣昌东街', '同济南路', '亦庄线', 2.3370, NULL);
INSERT INTO `links` VALUES ('莲花桥', '公主坟', '十号线', 1.0160, NULL);
INSERT INTO `links` VALUES ('菜市口', '虎坊桥', '七号线', 0.8850, NULL);
INSERT INTO `links` VALUES ('菜市口', '陶然亭', '四号线', 1.2000, NULL);
INSERT INTO `links` VALUES ('蒲黄榆', '刘家窑', '五号线', 0.9050, NULL);
INSERT INTO `links` VALUES ('蒲黄榆', '方庄', '十四号东段', 1.4860, NULL);
INSERT INTO `links` VALUES ('虎坊桥', '珠市口', '七号线', 1.2050, NULL);
INSERT INTO `links` VALUES ('褡裢坡', '黄渠', '六号线', 1.2380, NULL);
INSERT INTO `links` VALUES ('西二旗', '龙泽', '十三号线', 3.6230, NULL);
INSERT INTO `links` VALUES ('西单', '天安门西', '一号线', 1.2170, NULL);
INSERT INTO `links` VALUES ('西单', '宣武门', '四号线', 0.8150, NULL);
INSERT INTO `links` VALUES ('西四', '灵境胡同', '四号线', 0.8690, NULL);
INSERT INTO `links` VALUES ('西土城', '牡丹园', '十号线', 1.3300, NULL);
INSERT INTO `links` VALUES ('西小口', '永泰庄', '八号线', 1.0410, NULL);
INSERT INTO `links` VALUES ('西局', '六里桥', '十号线', 1.5840, NULL);
INSERT INTO `links` VALUES ('西直门', '大钟寺', '十三号线', 2.8390, NULL);
INSERT INTO `links` VALUES ('西直门', '新街口', '四号线', 1.0250, NULL);
INSERT INTO `links` VALUES ('西直门', '车公庄', '二号线', 0.9090, NULL);
INSERT INTO `links` VALUES ('西红门', '高米店北', '大兴线', 1.8100, NULL);
INSERT INTO `links` VALUES ('西苑', '圆明园', '四号线', 1.6720, NULL);
INSERT INTO `links` VALUES ('西钓鱼台', '慈寿寺', '十号线', 1.2140, NULL);
INSERT INTO `links` VALUES ('角门东', '角门西', '十号线', 1.2540, NULL);
INSERT INTO `links` VALUES ('角门西', '公益西桥', '四号线', 0.9890, NULL);
INSERT INTO `links` VALUES ('角门西', '草桥', '十号线', 1.6880, NULL);
INSERT INTO `links` VALUES ('车公庄', '平安里', '六号线', 1.4430, NULL);
INSERT INTO `links` VALUES ('车公庄', '阜成门', '二号线', 0.9600, NULL);
INSERT INTO `links` VALUES ('车公庄西', '车公庄', '六号线', 0.8870, NULL);
INSERT INTO `links` VALUES ('车道沟', '长春桥', '十号线', 1.2050, NULL);
INSERT INTO `links` VALUES ('达官营', '广安门内', '七号线', 1.8740, NULL);
INSERT INTO `links` VALUES ('通州北关', '通运门', '六号线', 1.4680, NULL);
INSERT INTO `links` VALUES ('通州北苑', '果园', '八通线', 1.4650, NULL);
INSERT INTO `links` VALUES ('通运门', '北运河西', '六号线', 1.5430, NULL);
INSERT INTO `links` VALUES ('郝家府', '东夏园', '六号线', 1.3460, NULL);
INSERT INTO `links` VALUES ('郭公庄', '大葆台', '房山站', 1.4050, NULL);
INSERT INTO `links` VALUES ('郭庄子', '大井', '十三号线', 2.0440, NULL);
INSERT INTO `links` VALUES ('郭庄子', '大井', '十四号西段', 2.0440, NULL);
INSERT INTO `links` VALUES ('金台夕照', '国贸', '十号线', 0.8350, NULL);
INSERT INTO `links` VALUES ('金台路', '十里堡', '六号线', 2.0360, NULL);
INSERT INTO `links` VALUES ('金台路', '朝阳公园', '十四号东段', 1.0850, NULL);
INSERT INTO `links` VALUES ('长春桥', '火器营', '十号线', 0.9610, NULL);
INSERT INTO `links` VALUES ('长椿街', '宣武门', '二号线', 0.9290, NULL);
INSERT INTO `links` VALUES ('长阳', '篱笆房', '房山站', 2.1500, NULL);
INSERT INTO `links` VALUES ('阜成门', '复兴门', '二号线', 1.8320, NULL);
INSERT INTO `links` VALUES ('阜通', '望京', '十四号东段', 0.9030, NULL);
INSERT INTO `links` VALUES ('陶然亭', '北京南站', '四号线', 1.6430, NULL);
INSERT INTO `links` VALUES ('陶然桥', '永定门外', '十四号东段', 1.0630, NULL);
INSERT INTO `links` VALUES ('雍和宫', '北新桥', '五号线', 0.8660, NULL);
INSERT INTO `links` VALUES ('雍和宫', '安定门', '二号线', 0.7940, NULL);
INSERT INTO `links` VALUES ('霍营', '立水桥', '十三号线', 4.7850, NULL);
INSERT INTO `links` VALUES ('霍营', '育新', '八号线', 1.8940, NULL);
INSERT INTO `links` VALUES ('青年路', '褡裢坡', '六号线', 3.9990, NULL);
INSERT INTO `links` VALUES ('顺义', '俸伯', '十五号', 2.4410, NULL);
INSERT INTO `links` VALUES ('首经贸', '丰台站', '十号线', 1.7170, NULL);
INSERT INTO `links` VALUES ('马家堡', '角门西', '四号线', 0.8270, NULL);
INSERT INTO `links` VALUES ('马泉营', '孙河', '十五号', 3.3090, NULL);
INSERT INTO `links` VALUES ('高家园', '望京南', '十四号东段', 0.6760, NULL);
INSERT INTO `links` VALUES ('高碑店', '传媒大学', '八通线', 2.0020, NULL);
INSERT INTO `links` VALUES ('高米店北', '高米店南', '大兴线', 1.1280, NULL);
INSERT INTO `links` VALUES ('高米店南', '枣园', '大兴线', 1.0960, NULL);
INSERT INTO `links` VALUES ('魏公村', '国家图书馆', '四号线', 1.6580, NULL);
INSERT INTO `links` VALUES ('黄村火车站', '义和庄', '大兴线', 2.0350, NULL);
INSERT INTO `links` VALUES ('黄村西大街', '黄村火车站', '大兴线', 0.9870, NULL);
INSERT INTO `links` VALUES ('黄渠', '常营', '六号线', 1.8540, NULL);
INSERT INTO `links` VALUES ('鼓楼大街', '什刹海', '八号线', 1.1880, NULL);
INSERT INTO `links` VALUES ('鼓楼大街', '积水潭', '二号线', 1.7660, NULL);
INSERT INTO `links` VALUES ('龙泽', '回龙观', '十三号线', 1.4230, NULL);

SET FOREIGN_KEY_CHECKS = 1;
