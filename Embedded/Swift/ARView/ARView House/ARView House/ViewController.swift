//
//  ViewController.swift
//  ARView House
//
//  Created by Harry O'Brien on 25/06/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

import UIKit
import ARKit

class ViewController: UIViewController {

  let config = ARWorldTrackingConfiguration()
  
  override func viewDidLoad() {
    super.viewDidLoad()

    sceneView.debugOptions = [ARSCNDebugOptions.showFeaturePoints, ARSCNDebugOptions.showWorldOrigin]
    sceneView.session.run(config, options: .resetTracking)
    sceneView.autoenablesDefaultLighting = true
  }

  @IBOutlet weak var sceneView: ARSCNView!
  
  @IBAction func add(_ sender: Any) {
    let node = SCNNode()
    node.geometry = SCNBox(width: 0.1, height: 0.1, length: 0.1, chamferRadius: 0.03)
    node.geometry?.firstMaterial?.specular.contents = UIColor.white
    node.geometry?.firstMaterial?.diffuse.contents = UIColor.blue
    node.position = SCNVector3(0,0,0)
    sceneView.scene.rootNode.addChildNode(node)
  }
  @IBAction func reset(_ sender: Any) {
    restartSession()
  }
  
  func restartSession() {
    sceneView.session.pause()
    sceneView.scene.rootNode.enumerateChildNodes {(node, _) in
      node.removeFromParentNode()
    }
    sceneView.session.run(config, options: [.resetTracking, .removeExistingAnchors])
  }
}

